import sys
import os
from functools import partial

from PyQt5.QtCore import Qt
from PyQt5.QtGui import QIcon, QKeySequence
from PyQt5.QtWidgets import (
    QAction,
    QApplication,
    QLabel,
    QMainWindow,
    QMenu,
    QSpinBox,
    QToolBar,
    QFileSystemModel,
    QTreeView,
    QLineEdit,
    QVBoxLayout,
    QCheckBox,
    QWidget,
    QListWidget,
    QListWidgetItem,
    QPushButton,
    QGridLayout
)

# NOTE: Uncomment this import to enable icons
# import qrc_resources


class CViewGui(QMainWindow):
    """Main Window."""

    def __init__(self, parent=None):
        """Initializer."""
        super().__init__(parent)
        self.setWindowTitle(sys.argv[0])
        self.resize(600, 400)
        self.row = 0 # idx of GUI row to mount layout
        
        self.centralWidget = QWidget(self)
        self.centralLayout = QGridLayout()
        
        self.centralWidget.setLayout(self.centralLayout)
        self.setCentralWidget(self.centralWidget)
        
        self._createActions()
        self._createMenuBar()
        self._createToolBars()

        self._connectActions()
        self._createFileExplorer()
        self._createFunctionSelector()
        
        self._createStatusBar()

    def guiRow(self):
        self.row+=1
        return self.row

    def setRootDir(self, path):
        self.leRootDir.setText(path)
        self.fsModel.setRootPath(path)

    def _createMenuBar(self):
        menuBar = self.menuBar()
        helpMenu = menuBar.addMenu(QIcon(":help-content.svg"), "&Help")
        helpMenu.addAction(self.helpContentAction)
        helpMenu.addAction(self.aboutAction)

    def _createToolBars(self):
        # Edit toolbar
        editToolBar = QToolBar("Edit", self)
        self.addToolBar(editToolBar)
        # Widgets
        self.demo = QLabel('demo')
        editToolBar.addWidget(self.demo)

    def _createStatusBar(self):
        self.statusbar = self.statusBar()
        self.statusbar.showMessage("Ready", 3000)
        # Permanent widget
#        self.wcLabel = QLabel(f"{self.getWordCount()} Words")
#        self.statusbar.addPermanentWidget(self.wcLabel)

    def _createActions(self):
         # Help actions
        self.helpContentAction = QAction("&Help Content...", self)
        self.aboutAction = QAction("&About...", self)

    def _connectActions(self):
        # Connect Help actions
        self.helpContentAction.triggered.connect(self.helpContent)
        self.aboutAction.triggered.connect(self.about)

    def _createFileExplorer(self):
        self.leRootDir = QLineEdit()
        self.lbFileTree = QLabel("Double click C file to list functions")
        self.fsModel = QFileSystemModel()
        self.fsModel.setRootPath('.')
        self.fsModel.setReadOnly(True)
        self.tvFileTree = QTreeView()
        self.tvFileTree.setModel(self.fsModel)
        self.tvFileTree.setAnimated(False)
        self.tvFileTree.setIndentation(20)
        self.tvFileTree.setSortingEnabled(True)
        
        self.centralLayout.addWidget(self.leRootDir, self.guiRow(),0,1,0)
        self.centralLayout.addWidget(self.lbFileTree, self.guiRow(),0,1,0)
        self.centralLayout.addWidget(self.tvFileTree, self.guiRow(),0,1,0)

        # connect stuff
        self.leRootDir.editingFinished.connect(self.updateRootTree)

    def _createFunctionSelector(self):
        self.labelSelection = QLabel('Selected functions to show:')
        self.cbAutoRefresh = QCheckBox('Auto refresh')

        self.lwSelectionList = QListWidget()
        for i in range(5):
            text = f'Item {i}'
            item = QListWidgetItem(text)
            item.setFlags(item.flags() | Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
            self.lwSelectionList.addItem(item)

        self.leSelectionRegex = QLineEdit()
        self.leSelectionRegex.setPlaceholderText('filter (regex)')

        self.btSelectAll = QPushButton('All')
        self.btSelectNone = QPushButton('None')
        
        row = self.guiRow()
        self.centralLayout.addWidget(self.labelSelection, row,0)
        self.centralLayout.addWidget(self.cbAutoRefresh,  row,1)
        
        self.centralLayout.addWidget(self.lwSelectionList, self.guiRow(),0,1,0)
        self.centralLayout.addWidget(self.leSelectionRegex, self.guiRow(),0,1,0)
        
        row = self.guiRow()
        self.centralLayout.addWidget(self.btSelectAll,  row,0)
        self.centralLayout.addWidget(self.btSelectNone, row,1)

        # connect stuff
        self.btSelectAll.clicked.connect(self.selectAllFromList)
        self.btSelectNone.clicked.connect(self.selectNoneFromList)


# Slots
    def helpContent(self):
        # Logic for launching help goes here...
        self.centralWidget.setText("<b>Help > Help Content...</b> clicked")

    def about(self):
        # Logic for showing an about dialog content goes here...
        self.centralWidget.setText("<b>Help > About...</b> clicked")

    def selectAllFromList(self):
        for i in range(self.lwSelectionList.count()):
            print(i, self.lwSelectionList.item(i))

    def selectNoneFromList(self):
        for i in range(self.lwSelectionList.count()):
            print(i, self.lwSelectionList.item(i))

    def updateRootTree(self):
        src = self.leRootDir.text()
        treeRoot = self.fsModel.rootPath()
        print(src, treeRoot)

        if os.path.abspath(src) == os.path.abspath(treeRoot):
            return

        if not os.path.isdir(src):
            print(f'rollback to tree root {treeRoot}')
            self.leRootDir.setText(treeRoot)
        else:
            print(f'move to {src}')




        