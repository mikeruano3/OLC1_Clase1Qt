#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <string>
#include <QString>
#include "qlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "qdebug.h"
#include <fstream>
#include <QTextStream>
#include <QMessageBox>
#include "Gramatica/parser.h"
#include "Gramatica/scanner.h"
#include "Gramatica/Arbol/NodoAST.h"
#include "Gramatica/Arbol/ListaNodoAST.h"
#include "Expresion/operacion.h"
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_BotonAnalizar_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
