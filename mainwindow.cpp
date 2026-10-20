#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(std::make_unique<Ui::MainWindow>())
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    
    QBrush blueBrush(Qt::blue);
    QPen blackPen(Qt::black);
    QPen redPen(Qt::red);
    QPen greenPen(Qt::green);

    ui->graphicsView->scale(1, -1);

    QGraphicsEllipseItem *ellipseItem = scene->addEllipse(0, 0, 100, 100, blackPen, blueBrush);
 
    scene->addLine(0, 0, 100, 100, redPen);
    scene->addLine(0, 100, 0, 0, greenPen);
}

MainWindow::~MainWindow() = default;

