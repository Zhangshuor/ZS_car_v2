//
// Created by zhangshuo on 2022/3/20.
//

#include "Wheel.h"

Wheel::Wheel(Motor motor, Encoder encoder): motor(motor), encoder(encoder),pid(150,0,150){

}

Wheel::~Wheel() {

}
/********************************************************************************
* @author: ��˶
* @params: float targetSpeed
* @return:
* @description: ���ת���ﵽĿ��ת��
********************************************************************************/

void Wheel::updateTargetVel(float targetSpeed) {
    if(this->targetSpeed!=targetSpeed){
        //����Ŀ���ٶ�
        this->targetSpeed = targetSpeed;
        //����PID
        pid.reset();
    }

}

void Wheel::init() {
    //���ĳ�ʼ��
    this->motor.init();
    //��������ʼ��
    this->encoder.init();
}
/********************************************************************************
* @author: ��˶
* @params:
* @return:
* @description:����ת��,���ٶ��ȶ����趨Ŀ���ٶ�����
********************************************************************************/

void Wheel::spin() {
    //Ҫ֪����ǰ���ٶ�
    if(HAL_GetTick()-startTime<((float)1000)/MOVE_CTRL_RATE){
        return;
    }
    //����ʱ��
    startTime = HAL_GetTick();
    //��ȡ����
    short nums = encoder.read();
    //�ٶ�
    curSpeed =((float) nums) / WHEEL_TPR * WHEEL_DIAMETER * M_PI * MOVE_CTRL_RATE;
    mylog("curSpeed:%d",(int)(curSpeed*100));
    //Ŀǰ��֪��Ŀ���ٶ�
    //ͨ��PID�����ݵ�ǰ�ٶȺ�Ŀ���ٶ�����ȡ��Ӧ��PWMֵ
    float pwm = pid.compute(this->targetSpeed,curSpeed);
    this->motor.spin((int)pwm);

}

float Wheel::getVel() {
    return this->curSpeed;
}
