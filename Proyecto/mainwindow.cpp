#include "mainwindow.h"
#include "ui_mainwindow.h"


extern int yyparse(); //
extern ListaNodoAST *raiz; // Raiz del arbol
extern int linea; // Linea del token
extern int columna; // Columna de los tokens
extern int yylineno;
extern void setSalida(QTextEdit* sal, QTextEdit* grafo);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BotonAnalizar_clicked()
{
    extern int linea;
    linea=1;


    QFile file("temp.txt"); //SE CREA UN ARCHIVO TEMPORAL PARA COMPILARLO
    if ( file.open( file.WriteOnly ) ) { //BUFFER PARA EL TEXTO QUE SE DESEA COMPILAR
        QTextStream stream1( &file );
        stream1 << ui->EntradaTexto->toPlainText();
    }

   setSalida(ui->SalidaTexto, ui->SalidaGrafo);//SE ASIGNA EL PUNTERO DE LA SALIDA PARA SER USADA POR BISON

    const char* x = "temp.txt";
    FILE* input = fopen(x, "r");
    yyrestart(input);
    yyparse();

    Entorno *ent = new Entorno();
    ent->consola = ui->SalidaTexto;
    QList<NodoAST*> nodos = raiz->misNodos;

    ent->consola->append("INFO::Iniciando recorrido del arbol.....");
    foreach(NodoAST *itemRaiz, nodos)
    {
        itemRaiz->ejecutar(ent);
    }

    Operacion *op = new Operacion("prueba", "prueba", 1, 2);
    op->tipo = "HOLAMUNDO";
    QObject *prue = dynamic_cast<QObject*>(op);
    Operacion *op1 = dynamic_cast<Operacion*>(prue);
    qDebug() << "Type of " ;


    QMessageBox msgBox;
    msgBox.setText("FIN DEL ANALISIS");
    msgBox.exec();
}

void MainWindow::on_pushButton_clicked()
{

}
