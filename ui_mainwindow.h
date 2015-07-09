/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPath;
    QAction *actionShowGraph;
    QAction *actionGenerate;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEditRootPath;
    QTreeView *fileSystemTreeView;
    QFrame *line;
    QCheckBox *checkBoxRefresh;
    QLabel *labelFunctions;
    QListWidget *listWidgetFunctions;
    QLineEdit *lineEditFilter;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonAll;
    QPushButton *pushButtonNone;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(540, 661);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/fork-8x.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionPath = new QAction(MainWindow);
        actionPath->setObjectName(QStringLiteral("actionPath"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/images/folder-2x.png"), QSize(), QIcon::Normal, QIcon::On);
        actionPath->setIcon(icon1);
        actionShowGraph = new QAction(MainWindow);
        actionShowGraph->setObjectName(QStringLiteral("actionShowGraph"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/images/eye-2x.png"), QSize(), QIcon::Normal, QIcon::On);
        actionShowGraph->setIcon(icon2);
        actionGenerate = new QAction(MainWindow);
        actionGenerate->setObjectName(QStringLiteral("actionGenerate"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/images/share-boxed-2x.png"), QSize(), QIcon::Normal, QIcon::On);
        actionGenerate->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEditRootPath = new QLineEdit(centralWidget);
        lineEditRootPath->setObjectName(QStringLiteral("lineEditRootPath"));

        gridLayout->addWidget(lineEditRootPath, 0, 0, 1, 2);

        fileSystemTreeView = new QTreeView(centralWidget);
        fileSystemTreeView->setObjectName(QStringLiteral("fileSystemTreeView"));

        gridLayout->addWidget(fileSystemTreeView, 1, 0, 1, 2);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 2, 0, 2, 2);

        checkBoxRefresh = new QCheckBox(centralWidget);
        checkBoxRefresh->setObjectName(QStringLiteral("checkBoxRefresh"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBoxRefresh->sizePolicy().hasHeightForWidth());
        checkBoxRefresh->setSizePolicy(sizePolicy1);
        checkBoxRefresh->setMaximumSize(QSize(100, 16777215));
        checkBoxRefresh->setLayoutDirection(Qt::LeftToRight);
        checkBoxRefresh->setChecked(true);

        gridLayout->addWidget(checkBoxRefresh, 3, 1, 2, 1);

        labelFunctions = new QLabel(centralWidget);
        labelFunctions->setObjectName(QStringLiteral("labelFunctions"));

        gridLayout->addWidget(labelFunctions, 4, 0, 1, 1);

        listWidgetFunctions = new QListWidget(centralWidget);
        listWidgetFunctions->setObjectName(QStringLiteral("listWidgetFunctions"));

        gridLayout->addWidget(listWidgetFunctions, 5, 0, 1, 2);

        lineEditFilter = new QLineEdit(centralWidget);
        lineEditFilter->setObjectName(QStringLiteral("lineEditFilter"));

        gridLayout->addWidget(lineEditFilter, 6, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonAll = new QPushButton(centralWidget);
        pushButtonAll->setObjectName(QStringLiteral("pushButtonAll"));

        horizontalLayout->addWidget(pushButtonAll);

        pushButtonNone = new QPushButton(centralWidget);
        pushButtonNone->setObjectName(QStringLiteral("pushButtonNone"));

        horizontalLayout->addWidget(pushButtonNone);


        gridLayout->addLayout(horizontalLayout, 7, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 540, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actionPath);
        mainToolBar->addAction(actionGenerate);
        mainToolBar->addAction(actionShowGraph);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "cflow-gui", 0));
        actionPath->setText(QApplication::translate("MainWindow", "Change Path", 0));
#ifndef QT_NO_TOOLTIP
        actionPath->setToolTip(QApplication::translate("MainWindow", "Change Path", 0));
#endif // QT_NO_TOOLTIP
        actionPath->setShortcut(QApplication::translate("MainWindow", "Alt+E", 0));
        actionShowGraph->setText(QApplication::translate("MainWindow", "Show graph", 0));
#ifndef QT_NO_TOOLTIP
        actionShowGraph->setToolTip(QApplication::translate("MainWindow", "Show Graph as PDF", 0));
#endif // QT_NO_TOOLTIP
        actionShowGraph->setShortcut(QApplication::translate("MainWindow", "Alt+S", 0));
        actionGenerate->setText(QApplication::translate("MainWindow", "Generate", 0));
#ifndef QT_NO_TOOLTIP
        actionGenerate->setToolTip(QApplication::translate("MainWindow", "Generate Graph", 0));
#endif // QT_NO_TOOLTIP
        actionGenerate->setShortcut(QApplication::translate("MainWindow", "Alt+R", 0));
        checkBoxRefresh->setText(QApplication::translate("MainWindow", "Auto refresh", 0));
        labelFunctions->setText(QApplication::translate("MainWindow", "Selected functions to show:", 0));
        lineEditFilter->setPlaceholderText(QApplication::translate("MainWindow", "Filter (regular expression)", 0));
        pushButtonAll->setText(QApplication::translate("MainWindow", "&All", 0));
        pushButtonNone->setText(QApplication::translate("MainWindow", "&None", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
