/********************************************************************************
* @author: 张硕
* @email: 2997605195@qq.com
* @date: 3.19
* @version: 1.0
* @description: 创建马达对象
********************************************************************************/
#include "cppmain.h"
#include "Motor.h"

//创建两个轮子对象
Motor motor_left(&htim8,TIM_CHANNEL_1,GPIOA,GPIO_PIN_2,GPIOA,GPIO_PIN_3,1);
Motor motor_right(&htim8,TIM_CHANNEL_2,GPIOA,GPIO_PIN_4,GPIOA,GPIO_PIN_5,-1);

void Init() {
//马达初始化
    motor_left.init();
    motor_right.init();


}

void Tick() {
//马达转动
    motor_left.spin(3000);
    motor_right.spin(3000);
}
