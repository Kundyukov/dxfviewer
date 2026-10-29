#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "core/entities.h"

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

    std::vector<Entity> entities = {
        Line{{0, 0}, {100, 100}},
        Circle{{50, 50}, 25}
    };
    
    for (const auto& entity : entities){
        std::visit(overloaded{
            [&](const Line &lineItem){
                scene->addLine(lineItem.start.x, lineItem.start.y, lineItem.end.x, lineItem.end.y, blackPen);
            },
            [&](const Circle &circleItem){
                scene->addEllipse(circleItem.center.x - circleItem.radius, circleItem.center.y - circleItem.radius, circleItem.radius * 2, circleItem.radius * 2, redPen, blueBrush);
            },
            [&](const Rectangle &rectangleItem){
                //scene->addRect(rectangleItem.position.x, rectangleItem.position.y, rectangleItem.width, rectangleItem.height, greenPen);
            },
            [&](const Polygon &polygonItem){QPolygonF qPolygon;
                for (const auto& vertex : polygonItem.vertices){
                    qPolygon << QPointF(vertex.x, vertex.y);
                }
                //scene->addPolygon(qPolygon, blackPen);
            }
        },entity);
    }
}

MainWindow::~MainWindow() = default;

