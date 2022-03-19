/********************************************************************************
* @author: 张硕
* @email: 2997605195@qq.com
* @date: 3.19
* @version: 1.0
* @description: 电机的头文件，定义电机，和电机的初始化，转动两个方法
********************************************************************************/

#ifndef ZS_CAR_V2_MOTOR_H
#define ZS_CAR_V2_MOTOR_H

#include "tim.h"
#include "config.h"
#include "math.h"

// 马达
// 属性：定时器 CHANNEL 第一个GPIO 第一个GPIO编号 第二个GPIO 第二个GPIO编号
// 行为：马达转动
class Motor {
private:
    // 定时器
    TIM_HandleTypeDef *htim;
    // channel
    uint32_t channel;
    //GPIOA
    GPIO_TypeDef *gpioA;
    uint16_t portA;
    //GPIOB
    GPIO_TypeDef *gpioB;
    uint16_t portB;
    //方向矫正 要么是1 要么-1
    int direction = 1;
public:
    Motor(TIM_HandleTypeDef *htim, uint32_t channel, GPIO_TypeDef *gpioA, uint16_t portA, GPIO_TypeDef *gpioB,
          uint16_t portB,int direction);

    ~Motor();
    // 初始化方法：做一些开启的操作
    void init();
//定义马达转动的函数
    void spin(int pwm);


};


#endif //ZS_CAR_V2_MOTOR_H
