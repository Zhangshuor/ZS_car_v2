//
// Created by Kaijun on 2020/9/11.
//
#include "PID.h"
#include <cstdio>

PID::PID(float kp, float ki, float kd) {
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
}

float PID::compute(float target, float current) {
    // �������
    float error = target - current;
    // �����ۼ�
    intergral +=error;
    // ����������һ�����Ĳ���
    derivative = error - prevError;

    // ����pid�Ĺ�ʽ
    pwm += kp*error + ki*intergral + kd*derivative;
    // ��¼��һ�ε����
    prevError = error;

    return pwm;
}

void PID::reset(){
    pwm = 0;
    intergral = 0;
    derivative = 0;
    prevError = 0;
}