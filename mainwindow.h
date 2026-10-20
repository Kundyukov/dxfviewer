#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>

#include <QMainWindow>
#

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
class GraphicsScene;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    std::unique_ptr<Ui::MainWindow> ui;

    QGraphicsScene *scene = nullptr;
};

#endif // MAINWINDOW_H
