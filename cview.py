
import sys
import os
from PyQt5.QtWidgets import QApplication

from cviewgui import *


if __name__ == "__main__":
    # Create the application
    app = QApplication(sys.argv)
    # Create and show the main window
    win = CViewGui()
    win.setRootDir(os.path.dirname(os.path.abspath('.')))
    win.show()
    # Run the event loop
    sys.exit(app.exec_())