//
// Created by zhangshuo on 2022/3/20.
//

#ifndef ZS_CAR_V2_WHEEL_H
#define ZS_CAR_V2_WHEEL_H

#include "Motor.h"
#include "Encoder.h"
#include "PID.h"
#include "my_log.h"
#include <stdio.h>

//马达 编码器
//属性
//行为：设置速度

class Wheel {
private:
    Motor motor;
    Encoder encoder;
    //定义一个目标速度
    float targetSpeed=0;
    //开始计时的时间
    float startTime = 0;
    //PID调节对象
    PID pid;
    //当前速度
    float curSpeed;

public:
    Wheel(Motor motor,Encoder encoder);

    ~Wheel();
    //轮子初始化
    void init();
    //设置目标速度m/s
    void updateTargetVel(float speed);
    //轮子转动,让速度稳定在设定目标速度左右
    void spin();
    //获取当前速度
    float getVel();
};


#endif //ZS_CAR_V2_WHEEL_H
