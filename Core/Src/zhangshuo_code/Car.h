//
// Created by zhangshuo on 2022/3/20.
//

#ifndef SMARTCAR_CAR_H
#define SMARTCAR_CAR_H

#include "Wheel.h"
//小车类
//属性: 轮子1和轮子2
//行为: 初始化(子控件初始化) spin(子控件不断运行) 接收树莓派指令(线速度和角速度  计算每个轮子转速) 获取线速度  获取角速度
class Car {
private:
    //左后方轮子
    Wheel backLWheel;
    //右后方轮子
    Wheel backRWheel;
public:
    Car(Wheel backLWheel,Wheel backRWheel);

    ~Car();
    //初始化
    void init();
    //不断执行
    void spin();
    /**
     * 小车移动
     * @param vel 线速度
     * @param anguler 角速度 正  左转  负 右转
     */
    void updateSpeed(float vel,float anguler);
    //获取线速度
    float getVel();
    //获取角速度
    float getAnguler();
};


#endif //SMARTCAR_CAR_H
