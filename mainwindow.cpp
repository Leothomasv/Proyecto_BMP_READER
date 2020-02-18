#define _CRT_SECURE_NO_WARNINGS
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fstream>
#include <iostream>
using namespace std;




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //print image

    FILE* file = fopen("C:\\Users\\leoth\\source\\repos\\Estructura de datos 2\\Proyecto_BMP\\m.bmp", "rb");
           unsigned char buffer[54];
           fread(buffer, sizeof(unsigned char), 54, file);

           int width = *(int*)&buffer[18];
           int height = *(int*)&buffer[22];
           QImage image =QImage(width,height,QImage::Format_RGB32);

           int relleno = (width * 3 + 3) & (~3);// se debe agregar por que los archivo bmp esperan que todas las filas esten alineadas en bytes multiples de 4
               unsigned char* data = new unsigned char[relleno];
               int R;
               int G;
               int B;

               for (int i = 0; i < height; i++)
               {
                   fread(data, sizeof(unsigned char), relleno, file);
                   int x = width;
                   for (int j = 0; j < width * 3 ; j += 3)
                   {

                       unsigned char tmp = data[j];
                       data[j] = data[j+2];
                       data[j+2] = tmp;

                       R=(int)data[j];
                       G=(int)data[j+1];
                       B=(int)data[j+2];

                       image.setPixel(--x,height-i-1,qRgb(R,G,B));

                   }
               }

    QGraphicsScene *graphic = new QGraphicsScene(this);
    graphic->addPixmap(QPixmap::fromImage(image));
    ui->graphicsView->setScene(graphic);

}

MainWindow::~MainWindow()
{
    delete ui;
}

