/********************************************************************************
* @author: 张硕
* @email: 2997605195@qq.com
* @date: ${DATE} ${TIME}
* @version: 1.0
* @description: 控制电机的文件
********************************************************************************/

#include "Motor.h"

Motor::Motor(TIM_HandleTypeDef *htim, uint32_t channel, GPIO_TypeDef *gpioA, uint16_t portA, GPIO_TypeDef *gpioB,
             uint16_t portB, int direction) {
    this->htim=htim;
    this->channel=channel;
    this->gpioA=gpioA;
    this->gpioB=gpioB;
    this->portA=portA;
    this->portB=portB;
    this->direction=direction;

}

Motor::~Motor() {

}
/********************************************************************************
* @author: 张硕
* @params: none
* @return:none
* @description: 进行电机的初始化，开启定时器，马达不转
********************************************************************************/

void Motor::init() {
    //开启定时器
    HAL_TIM_PWM_Start(this->htim,this->channel);
    //马达不转（RESET SET）
    HAL_GPIO_WritePin(this->gpioA, this->portA, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(this->gpioB, this->portB, GPIO_PIN_RESET);
}



/********************************************************************************
* @author: 张硕
* @params: pwm（有正有负）+:向前转；-：向后转
* @return:正反转
* @description:控制马达转动，给pwm
********************************************************************************/
void Motor::spin(int pwm) {
//pwm是否在我们所要求的范围内
    if(pwm>MAX_PWM){
        pwm = MAX_PWM;
    } else if(pwm<MIN_PWM){
        pwm = MIN_PWM;
    }
//    pwm时候在范围内
//    乘以矫正系数
    pwm*=direction;
    if(pwm>0){
//前
    HAL_GPIO_WritePin(this->gpioA, this->portA, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(this->gpioB, this->portB, GPIO_PIN_SET);
    } else if(pwm<0){
//后
    HAL_GPIO_WritePin(this->gpioA, this->portA, GPIO_PIN_SET);
    HAL_GPIO_WritePin(this->gpioB, this->portB, GPIO_PIN_RESET);
    }

    // 速度pwm
    __HAL_TIM_SET_COMPARE(this->htim, this->channel, abs(pwm));
}



