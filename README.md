# ProtectEarth

栾心仪 2019202381

（一）设计概念：
星球大战爆发在即，大量UFO向地球进攻。玩家将通过设置炮塔，击毁UFO，保护地球。


（二）开发流程：
一、绘制地图
在mainwindow.cpp中使用数组表示地图，用数组中不同的数字区分路径与背景。遍历数组，画出地图。

二、飞船类及其移动的实现
1.创建飞船类。将路径节点保存在飞船类下的动态数组中。
2.引入两个qtimer定时器。第一个用于每隔固定时间插入新飞船，第二个用于每隔固定时间刷新页面。
3.使用move函数判断飞船是否到达路径节点。若未到达则继续向下一个节点靠近，若到达节点则在动态数组中删除最新的节点，如此便实现了转弯功能。
4.飞船到达终点之后，删除飞船。
(2020/6/5完成至此)

四、塔类及其攻击的实现
1.创建塔类、塔坑类。同时创建鼠标点击事件，使得点击塔坑即可生成一个塔。
2.引入qtimer定时器和画笔，通过攻击范围的改变，实现塔的冲击波动画。

五、塔类和飞船类的互动
1.飞船与塔的距离小于等于当即攻击范围时，飞船生命值有相应的减少。
2.飞船生命值减少至零时，移除飞船；飞船行驶至地球而仍未被击落时，也移除飞船。

六、玩家经济及HP的引入
1.设置金币值并显示。生成塔花费金币，击沉飞船奖励金币。
2.设置地球HP值并显示。若飞船行驶至地球而未被击沉，地球HP值减少。

七、界面的完善
1.显示当前金币值及地球HP值。
2.在所有飞船被击沉后显示赢得游戏的信息，在地球HP减少至0后显示游戏失败的信息。
（2020/6/13完成至此）


（三）基本功能
1.多类型的敌人
2.游戏难度随游戏进度不断增加
