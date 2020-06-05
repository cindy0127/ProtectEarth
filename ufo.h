#ifndef UFO_H
#define UFO_H

#include <QVector>
#include <QString>
#include "wholestruct.h"   //坐标结构

//ufo类
class Ufo
{
private:
    QVector<CoorStr*> Waypoint;  //存储ufo路径点数组
    int mx, my;                  //ufo坐标
    int mwidth, mheight;         //ufo宽高
    QString ImgPath;             //ufo图片路径
    int id;                      //ufo种类
    int health;                  //ufo生命值
    int mspeed = 10;              //ufo移动速度

public:
    //参数：路径点数组、路径点的个数、ufo初始坐标、ufo宽度、ufo图片路径
    Ufo(CoorStr **pointarr, int arrlength, int x, int y, int fid);  //构造

    bool Move();            //ufo移动函数

    int GetX() const;       //获取横坐标
    int GetY() const;       //获取横坐标
    int GetWidth() const;   //获取宽
    int GetHeight() const;  //获取高
    QString GetImgPath() const; //获取图片路径
    int GetId() const;      //获取种类
    int GetHealth() const;  //获取生命值
    void SetHealth(int);    //设置生命值
};

#endif // UFO_H
