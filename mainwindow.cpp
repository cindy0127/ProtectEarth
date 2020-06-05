#include "mainwindow.h"
#include "ufo.h"
#include "ui_mainwindow.h"
#include "towerpit.h"


//通过格子确定路径点坐标
#define X40(num) ((num) - 1) * 40 + 5

//插入ufo  路径点数组名、ufo初始坐标、ufo种类
#define InsertUFO(PathNum, StaCoorNum, UFOId)  \
UfoVec.push_back(new Ufo(pointarr[PathNum], PathLength[PathNum], X40(staco[StaCoorNum].x), X40(staco[StaCoorNum].y), UFOId));


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(26*40,16*40);

    QTimer* timer1 = new QTimer(this);      //页面每0.08秒刷新一次
    timer1->start(80);
    QTimer* timer2 = new QTimer(this);      //ufo每8秒出来一艘
    timer2->start(8000);

    connect(timer2,&QTimer::timeout,[=]()
    {
        //设置路径点
        CoorStr* Waypointarr1[] = {new CoorStr(X40(4), X40(8)), new CoorStr(X40(20), X40(8)), new CoorStr(X40(20), X40(13)), new CoorStr(X40(6), X40(13)), new CoorStr(homecoor->x, homecoor->y)};
        CoorStr* Waypointarr2[] = {new CoorStr(X40(11), X40(8)), new CoorStr(X40(20), X40(8)), new CoorStr(X40(20), X40(13)), new CoorStr(X40(6), X40(13)), new CoorStr(homecoor->x, homecoor->y)};

        //ufo的起始点
        CoorStr staco[] = {CoorStr(4, 0), CoorStr(11, 0), CoorStr(4, -1), CoorStr(11, -1)};

        //每条路径的结点个数
        int PathLength[] = {sizeof(Waypointarr1)/sizeof(CoorStr*), sizeof(Waypointarr1)/sizeof(CoorStr*)};

         createUFO(Waypointarr1, Waypointarr2, staco, PathLength);
    });

    //ufo移动
    connect(timer1,&QTimer::timeout,[=]()
    {
        for (auto Moni = UfoVec.begin(); Moni != UfoVec.end(); Moni++)
        {
            if((*Moni)->Move()) //ufo走到终点
            {
                delete *Moni;
                UfoVec.erase(Moni);         //ufo走到终点则删除这个ufo
                break;
            }
        }
        update();
    });

}

MainWindow::~MainWindow()
{
    delete ui;

    for (auto it = TowerPitVec.begin(); it != TowerPitVec.end(); it++)
    {
        delete *it;
        *it = NULL;
    }

    for (auto it = TowerVec.begin(); it != TowerVec.end(); it++)
    {
        delete *it;
        *it = NULL;
    }

    for (auto it = UfoVec.begin(); it != UfoVec.end(); it++)
    {
        delete *it;
        *it = NULL;
    }
}

void MainWindow::DrawMap(QPainter& painter){
    int Map[16][26] =
    {
        0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 3, 6, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 6, 6, 1, 1, 0, 0, 3, 6, 0, 1, 1, 0, 0, 3, 6, 0, 0, 3, 6, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 0, 0, 6, 6, 0, 1, 1, 0, 0, 6, 6, 0, 0, 6, 6, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 3, 6, 0, 0, 0, 0, 3, 6, 0, 0, 0, 0, 3, 6, 1, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 6, 6, 0, 0, 0, 0, 6, 6, 0, 0, 0, 0, 6, 6, 1, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 5, 1, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 1, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };

    for (int j = 0; j < 16; j++)
        for (int i = 0; i < 26; i++)
        {
            switch (Map[j][i])
            {
            case 0:     /*宇宙*/
                painter.drawPixmap(i * 40, j * 40, 40, 40,
                    QPixmap(":/image/universe.png"));
                break;
            case 1:     /*星路*/
                painter.drawPixmap(i * 40, j * 40, 40, 40,
                    QPixmap(":/image/universe.png"));
                painter.drawPixmap(i * 40, j * 40, 40, 40,
                    QPixmap(":/image/starpath.png"));
                break;
            case 3:     /*光圈*/
                painter.drawPixmap(i * 40, j * 40, 80, 80,
                    QPixmap(":/image/halo.png"));
                break;
            case 5:     //家在循环中先输出宇宙，后再用房子图片覆盖
                painter.drawPixmap(i * 40, j * 40, 40, 40,
                    QPixmap(":/image/universe.png"));
                homecoor->x = i * 40, homecoor->y = j * 40;
                break;
            }
        }

    painter.drawPixmap(homecoor->x, homecoor->y, 80, 80,
        QPixmap(":/image/house.png")); //画出房子
}

void MainWindow::DrawUFO(QPainter& painter){
    for (auto moni : UfoVec)//画出ufo
        painter.drawPixmap(moni->GetX(), moni->GetY(), moni->GetWidth(), moni->GetHeight(), QPixmap(moni->GetImgPath()));
}

void MainWindow::createUFO(CoorStr** Waypointarr1, CoorStr** Waypointarr2, CoorStr* staco, int* PathLength)
{
    /*两条路径*/
    CoorStr** pointarr[] = {Waypointarr1, Waypointarr2};

    /*插入ufo*/
    if(counter >= 1 && counter <= 14)
    {//插入UFO1
        InsertUFO(0, 0, 1); //第几条路径、第几个起始点、ufo种类
    }
    else if(counter > 14 && counter <= 34)
    {//在、两路插入UFO1和UFO2
        InsertUFO(0, 0, 1);
        InsertUFO(1, 1, 2);
    }
    else if (counter > 34 && counter <= 35)
    {//两路插入ufo3
        InsertUFO(0, 0, 3);
        InsertUFO(1, 1, 3);
    }

    counter++;          //计数器+1
    update();
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    DrawMap(painter);        //画出地图
    DrawUFO(painter);        //画出ufo
}
