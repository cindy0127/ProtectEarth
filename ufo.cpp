#include "ufo.h"

Ufo::Ufo(CoorStr **pointarr, int arrlength, int x, int y, int fid) :
    mx(x), my(y), id(fid)
{
    for(int i = 0; i < arrlength; i++)      //将传进来的数组插入到Waypoint动态数组
        Waypoint.push_back(pointarr[i]);

    switch (id)
    {
    case 1:
        health = 100;   //生命值
        mwidth = 70, mheight = 70;  //宽高
        ImgPath = ":/image/ufo1.png";
        break;
    case 2:
        health = 120;
        mwidth = 70, mheight = 70;
        ImgPath = ":/image/ufo2.png";
        break;
    case 3:
        health = 300;
        mwidth = 80, mheight = 80;
        ImgPath = ":/image/ufo3.png";
        break;
    default:
        break;
    }
}

//ufo按设定路径点移动
bool Ufo::Move()
{
    if(Waypoint.empty())
        return true;

    if (Waypoint.at(0)->y > my) //下
    {
        my += mspeed;
        return false;
    }

    if (Waypoint.at(0)->x < mx) //左
    {
        mx -= mspeed;
        return false;
    }

    if (Waypoint.at(0)->x > mx) //右
    {
        mx += mspeed;
        return false;
    }

    if (Waypoint.at(0)->y < my) //上
    {
        my -= mspeed;
        return false;
    }

    if (Waypoint.at(0)->y == my && Waypoint.at(0)->x == mx)
    {
        Waypoint.erase(Waypoint.begin());       //把第一个路径点从数组中删除
    }

    return false;
}


int Ufo::GetX() const       //获取横坐标
{
    return mx;
}

int Ufo::GetY() const       //获取横坐标
{
    return my;
}

int Ufo::GetWidth() const   //获取宽
{
    return mwidth;
}

int Ufo::GetHeight() const  //获取高
{
    return mheight;
}

QString Ufo::GetImgPath() const //获取图片路径
{
    return ImgPath;
}

int Ufo::GetId() const      //获取种类
{
    return id;
}

int Ufo::GetHealth() const  //获取生命值
{
    return health;
}

void Ufo::SetHealth(int fhealth)//设置生命值
{
    health = fhealth;
}
