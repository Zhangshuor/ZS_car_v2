//
// Created by zhangshuo on 2022/3/20.
//

#include "Wheel.h"

Wheel::Wheel(Motor motor, Encoder encoder): motor(motor), encoder(encoder),pid(150,0,150){

}

Wheel::~Wheel() {

}
/********************************************************************************
* @author: 张硕
* @params: float targetSpeed
* @return:
* @description: 电机转动达到目标转速
********************************************************************************/

void Wheel::updateTargetVel(float targetSpeed) {
    if(this->targetSpeed!=targetSpeed){
        //更新目标速度
        this->targetSpeed = targetSpeed;
        //重置PID
        pid.reset();
    }

}

void Wheel::init() {
    //马达的初始化
    this->motor.init();
    //编码器初始化
    this->encoder.init();
}
/********************************************************************************
* @author: 张硕
* @params:
* @return:
* @description:轮子转动,让速度稳定在设定目标速度左右
********************************************************************************/

void Wheel::spin() {
    //要知道当前的速度
    if(HAL_GetTick()-startTime<((float)1000)/MOVE_CTRL_RATE){
        return;
    }
    //更新时间
    startTime = HAL_GetTick();
    //读取数据
    short nums = encoder.read();
    //速度
    curSpeed =((float) nums) / WHEEL_TPR * WHEEL_DIAMETER * M_PI * MOVE_CTRL_RATE;
    mylog("curSpeed:%d",(int)(curSpeed*100));
    //目前已知的目标速度
    //通过PID，根据当前速度和目标速度来获取相应的PWM值
    float pwm = pid.compute(this->targetSpeed,curSpeed);
    this->motor.spin((int)pwm);

}

float Wheel::getVel() {
    return this->curSpeed;
}
