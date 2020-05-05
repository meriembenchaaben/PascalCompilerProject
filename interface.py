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
browseButton = window.findChild(QtWidgets.QPushButton, 'ParcourirButton')
compilationButton = window.findChild(QtWidgets.QPushButton, 'compilationButton')
resultsTextEdit = window.findChild(QtWidgets.QTextEdit, 'ResultsTextEdit')
FileRadioButton = window.findChild(QtWidgets.QRadioButton, 'FileRadioButton')
NoFileRadioButton = window.findChild(QtWidgets.QRadioButton, 'NoFileRadioButton')
code = window.findChild(QtWidgets.QTextEdit, 'Code')

root = tk.Tk()
root.withdraw()


def setFileToCompile():
    file_name = filedialog.askopenfilename()
    sourceLineEdit.setText(file_name)


def menu():
    resultsTextEdit.setTextColor(QtGui.QColor(0,0,0))
    path = ""
    if FileRadioButton.isChecked():
        path = sourceLineEdit.text()
    else:
        file = open("to_compile.txt", "w")
        file.write(code.toPlainText())
        file.close()
        path = "to_compile.txt"
    out = subprocess.Popen("pascal3.exe " + path, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    stdout, stderr = out.communicate()
    if out.returncode == 1 :
        resultsTextEdit.setTextColor(QtGui.QColor(255,0,0))
    resultsTextEdit.setText(stdout.decode("utf-8"))


browseButton.clicked.connect(setFileToCompile)
compilationButton.clicked.connect(menu)

app.exec_()
