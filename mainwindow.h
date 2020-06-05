#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>         //画家
#include <QMouseEvent>      //鼠标事件
#include <QWidget>
#include <QTimer>           //定时器
#include <QLabel>
#include <QString>
#include "ufo.h"
#include "wholestruct.h"
#include "towerparent.h"
#include "towerpit.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QVector<TowerPit*> TowerPitVec;         //塔坑数组
    QVector<TowerParent*> TowerVec;         //塔父类数组
    QVector<Ufo*> UfoVec;                   //ufo数组

    CoorStr *homecoor = new CoorStr(0, 0);  //记录家的坐标

    int counter = 0;    //产生ufo的计数器
    void createUFO(CoorStr**, CoorStr**, CoorStr*,int*); //产生ufo

    bool inGame;
    int timerId1; //第一个时间控制器，刷新页面
    int timerId2; //第二个时间控制器，产生敌人

protected:
    void paintEvent(QPaintEvent *);         //画图事件
    void DrawUFO(QPainter&);                //画出ufo
    void DrawMap(QPainter&);                //画出地图
};
#endif // MAINWINDOW_H
