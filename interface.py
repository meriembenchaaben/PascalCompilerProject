import tkinter as tk
from tkinter import filedialog
from typing import List, Set, Dict, Tuple, Optional
from PyQt5 import QtWidgets, QtCore, QtGui, uic
import os
import sys
import subprocess
import tempfile




class Ui(QtWidgets.QDialog):

    def __init__(self):
        super(Ui, self).__init__()
        uic.loadUi('Interface.ui', self)

        self.show()


app = QtWidgets.QApplication(sys.argv)
window = Ui()

sourceLineEdit = window.findChild(QtWidgets.QLineEdit, 'source')
parcourirButton = window.findChild(QtWidgets.QPushButton, 'ParcourirButton')
compilationButton = window.findChild(QtWidgets.QPushButton, 'compilationButton')
resultsTextEdit = window.findChild(QtWidgets.QTextEdit, 'ResultsTextEdit')
root = tk.Tk()
root.withdraw()



def setFileToCompile():
    file_name = filedialog.askopenfilename()
    sourceLineEdit.setText(file_name)



def compile_():
    out = subprocess.Popen("pascal.exe " + sourceLineEdit.text(),stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    stdout,stderr= out.communicate()
    print(type(stdout))
    resultsTextEdit.setText("stdout = "+ stdout.decode("utf-8"))


parcourirButton.clicked.connect(setFileToCompile)
compilationButton.clicked.connect(compile_)


app.exec_()
