#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileSystemModel>
#include <QModelIndex>
#include <QListWidgetItem>
#include <QStringList>
#include <QProcess>

namespace Ui {
class MainWindow;
}

/**
sudo apt-get install python-setuptools python-pip graphviz
sudo pip install --upgrade virtualenv
easy_install --upgrade pip

*/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *model;
    QString rootPath;
    QStringList excludedFunctions;
    QString currentPath;
    QString currentFile;
    QString outputFile;
    QProcess *viewer;

    QStringList loadFileFunctions(QString path);
    void fillFunctionsPanel(QStringList functions);
    QStringList nonSelectedFunctions();
    bool generateGraph(QString inFilePath, QStringList excludedFunctions, QString outFilePath);
    bool showGraph(QString filePath);


public slots:
    void updateFileTreeRoot();
    void itemSelected(QModelIndex idx);
    void showClickedDir(QModelIndex idx);
    void resizeOnClick();
    void focusToUserInput();

    void functionListFilter(QString text);
    void functionListSelectedAll();
    void functionListSelectedNone();
    void functionListSelectedChanged(QListWidgetItem *item);

    void generateGraph();
    void viewerOpen();
    void viewerClosed(int ret);
};

#endif // MAINWINDOW_H
