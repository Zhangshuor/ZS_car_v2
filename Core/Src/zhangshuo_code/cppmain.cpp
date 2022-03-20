/********************************************************************************
* @author: 张硕
* @email: 2997605195@qq.com
* @date: 3.19
* @version: 1.0
* @description: 创建马达对象
********************************************************************************/
#include "cppmain.h"
#include "Motor.h"
#include "Encoder.h"
#include "Wheel.h"
#include "my_log.h"
#include <stdio.h>

//创建两个轮子对象
Motor motor_left(&htim8,TIM_CHANNEL_1,GPIOA,GPIO_PIN_2,GPIOA,GPIO_PIN_3,1);
Motor motor_right(&htim8,TIM_CHANNEL_2,GPIOA,GPIO_PIN_4,GPIOA,GPIO_PIN_5,-1);
//创建编码器对象
Encoder encoder_left(&htim2,TIM_CHANNEL_1|TIM_CHANNEL_2,-1);
Encoder encoder_right(&htim3,TIM_CHANNEL_1|TIM_CHANNEL_2,1);
//创建轮子对象
Wheel wheel_left(motor_left,encoder_left);
Wheel wheel_right(motor_right,encoder_right);

void Init() {
//    //马达初始化
//    motor_left.init();
//    motor_right.init();
//    //编码器初始化
//    encoder_left.init();
//    encoder_right.init();
//    //马达转动
//    motor_left.spin(3000);
//    motor_right.spin(3000);
//轮子初始化
    wheel_left.init();
    wheel_right.init();
//   更新速度
    wheel_left.updateTargetVel(0.1);
    wheel_right.updateTargetVel(0.1);



}

void Tick() {
//    //获取计数数据
//    HAL_Delay(1000);
//    short left_counter = encoder_left.read();
//    short right_counter = encoder_right.read();
//
//    log("encoder:%hd,%hd",left_counter,right_counter);
//不断更新速度
    wheel_left.spin();
    wheel_right.spin();

}
