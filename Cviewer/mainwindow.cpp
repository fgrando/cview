#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
#include <QModelIndex>
#include <QFileInfo>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    model(new QFileSystemModel)
{
    ui->setupUi(this);

//    QString path = QDir::currentPath();
    rootPath = QDir::rootPath();
    outputFile = "/tmp/output";

    model->setRootPath(rootPath);
    model->setReadOnly(true);
    ui->fileSystemTreeView->setModel(model);
    QModelIndex idx = model->index(rootPath);
    itemSelected(idx);

/*
    //thanks http://www.bogotobogo.com/Qt/Qt5_QTreeView_QDirModel_ModelView_MVC.php
    QModelIndex index = model->index(path);
    ui->fileSystemTreeView->expand(index);
    ui->fileSystemTreeView->scrollTo(index);
    ui->fileSystemTreeView->setCurrentIndex(index);
*/

    QObject::connect(ui->lineEditRootPath, SIGNAL(editingFinished()),
                     this, SLOT(updateFileTreeRoot()));
    QObject::connect(ui->fileSystemTreeView, SIGNAL(doubleClicked(QModelIndex)),
                     this, SLOT(itemSelected(QModelIndex)));
    QObject::connect(ui->fileSystemTreeView, SIGNAL(clicked(QModelIndex)),
                     this, SLOT(showClickedDir(QModelIndex)));
    QObject::connect(ui->fileSystemTreeView, SIGNAL(clicked(QModelIndex)),
                     this, SLOT(resizeOnClick()));
    QObject::connect(ui->actionPath, SIGNAL(triggered(bool)),
                     this, SLOT(setupUserInput()));
    QObject::connect(ui->actionShowGraph, SIGNAL(triggered(bool)),
                     this, SLOT(openViewer()));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateFileTreeRoot()
{
    QFileInfo file(ui->lineEditRootPath->text());

    if (!file.exists()) {
        ui->lineEditRootPath->setText(rootPath);
        setupUserInput();
        return;
    }

    this->setFocus();

    if (!file.isDir())
        return;

    qDebug() << "expanding current dir" << file.absoluteFilePath();
    QModelIndex idx = model->index(file.absoluteFilePath());
    ui->fileSystemTreeView->setRootIndex(idx);
}

void MainWindow::itemSelected(QModelIndex idx)
{
    QFileInfo file = model->fileInfo(idx);
    if (file.isDir()) {
        ui->lineEditRootPath->setText(file.absoluteFilePath());
        ui->fileSystemTreeView->setRootIndex(idx);
        qDebug() << "new root: " << file.absoluteFilePath();

    } else {
        currentFile = file.canonicalFilePath();
        qDebug() << "processing: " << currentFile;
        fillFunctionsPanel(loadFileFunctions(currentFile));
        generateGraph(currentFile, excludedFunctions, outputFile);
    }
}

void MainWindow::showClickedDir(QModelIndex idx)
{
    QFileInfo file = model->fileInfo(idx);
    if (file.isDir())
        qDebug() << "abrir a pasta: " << file.absoluteFilePath();
}

void MainWindow::resizeOnClick()
{
    ui->fileSystemTreeView->resizeColumnToContents(0);
    qDebug() << "resizing collumn";
}

void MainWindow::setupUserInput()
{
    ui->lineEditRootPath->setFocus();
    ui->lineEditRootPath->selectAll();
}

void MainWindow::checkFunctionSelection(QListWidgetItem *item)
{
    qDebug() << item->text() << " selection changed! " << item->checkState();

    if (item->checkState() == Qt::Checked) {
        for (int i = 0; i < excludedFunctions.size(); i++) {
            if (excludedFunctions[i] == item->text()) {
                qDebug() << "removing " << item->text();
                excludedFunctions.removeAt(i);
                break;
            }
        }

    } else {
        qDebug() << "adding " << item->text();
        excludedFunctions.append(item->text());
    }

    qDebug() << "generating " << outputFile;
    generateGraph(currentFile, excludedFunctions, outputFile);

}

void MainWindow::openViewer()
{
    showGraph(outputFile+"0.pdf");
}

void MainWindow::fillFunctionsPanel(QStringList functions)
{
    QObject::disconnect(ui->listWidgetFunctions, SIGNAL(itemChanged(QListWidgetItem*)),
                     this, SLOT(checkFunctionSelection(QListWidgetItem*)));

    ui->listWidgetFunctions->clear();
    excludedFunctions.clear();

    foreach (QString str, functions) {
        qDebug() << "adding " << str;
        QListWidgetItem *item = new QListWidgetItem(str, ui->listWidgetFunctions);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable); // set checkable flag
        item->setCheckState(Qt::Checked); // AND initialize check state
    }

    QObject::connect(ui->listWidgetFunctions, SIGNAL(itemChanged(QListWidgetItem*)),
                     this, SLOT(checkFunctionSelection(QListWidgetItem*)));
}


QStringList MainWindow::loadFileFunctions(QString path)
{
    qDebug() << "load file functions " << path;

    // cflow options:
    /* -I include dir to be searched for headers (root)
     * -x cross-reference listing only
    */
    QString program;
    QStringList arguments;
    QProcess *cflow = new QProcess(this);
    QStringList functions;

    program = "cflow";
    arguments.append("-x");
    arguments.append(path);
    cflow->start(program, arguments);
    cflow->waitForFinished(30000);

    QStringList lines = QString::fromStdString(cflow->readAllStandardOutput().toStdString()).split('\n');
    foreach (QString line, lines) {
        QString tmp = line.split(' ')[0];
        if (tmp != "") {
            functions.append(tmp);
            qDebug() << tmp;
        }
    }

    functions.removeDuplicates();
    excludedFunctions.clear();
    return functions;
}

QStringList MainWindow::nonSelectedFunctions()
{
    return excludedFunctions;
}

bool MainWindow::generateGraph(QString inFilePath, QStringList excludedFunctions, QString outFilePath)
{
    //sudo apt-get install cflow graphviz cpp python python-networkx
    QString program;
    QStringList arguments;
    QProcess *pycflow2dot = new QProcess(this);
    QString excluded = "/tmp/excluded.txt"; //TODO: non portable

    QFile file(excluded);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream (&file);
        foreach (QString str, excludedFunctions) {
            stream << str << endl;
        }
        file.close();
    }

    program = "./pycflow2dot.py"; //TODO: non portable
    arguments.append("-i");
    arguments.append(inFilePath);
    arguments.append("-f");
    arguments.append("pdf");
    arguments.append("-x");
    arguments.append(excluded);
    arguments.append("-o");
    arguments.append(outFilePath);

    pycflow2dot->start(program, arguments);
    pycflow2dot->waitForFinished(30000);

    QString ret = QString::fromStdString(pycflow2dot->readAllStandardOutput().toStdString());

    qDebug() << ret;

    return true;
}

bool MainWindow::showGraph(QString filePath)
{
    qDebug() << "showing " << filePath;

    QString program = "/usr/bin/evince";
    QStringList arguments;
    arguments.append(filePath);

    QProcess::startDetached(program, arguments);
    return true;
}

