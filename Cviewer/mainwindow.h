#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileSystemModel>
#include <QModelIndex>
#include <QListWidgetItem>
#include <QStringList>

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
    void processFile(QString path);
    void fillFunctionsPanel(QStringList functions);

    QStringList excludedFunctions;
    QStringList loadFileFunctions(QString path);
    QStringList nonSelectedFunctions();
    bool generateGraph(QString inFilePath, QStringList excludedFunctions, QString outFilePath);
    bool showGraph(QString filePath);

    QString currentFile;
    QString outputFile;

public slots:
    void updateFileTreeRoot();
    void itemSelected(QModelIndex idx);
    void showClickedDir(QModelIndex idx);
    void resizeOnClick();
    void setupUserInput();
    void checkFunctionSelection(QListWidgetItem *item);
    void openViewer();
};

#endif // MAINWINDOW_H
