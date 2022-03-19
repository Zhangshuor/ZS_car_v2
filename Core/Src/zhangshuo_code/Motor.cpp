/********************************************************************************
* @author: ��˶
* @email: 2997605195@qq.com
* @date: ${DATE} ${TIME}
* @version: 1.0
* @description: ���Ƶ�����ļ�
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
* @author: ��˶
* @params: none
* @return:none
* @description: ���е���ĳ�ʼ����������ʱ������ﲻת
********************************************************************************/

void Motor::init() {
    //������ʱ��
    HAL_TIM_PWM_Start(this->htim,this->channel);
    //��ﲻת��RESET SET��
    HAL_GPIO_WritePin(this->gpioA, this->portA, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(this->gpioB, this->portB, GPIO_PIN_RESET);
}



/********************************************************************************
* @author: ��˶
* @params: pwm�������и���+:��ǰת��-�����ת
* @return:����ת
* @description:�������ת������pwm
********************************************************************************/
void Motor::spin(int pwm) {
//pwm�Ƿ���������Ҫ��ķ�Χ��
    if(pwm>MAX_PWM){
        pwm = MAX_PWM;
    } else if(pwm<MIN_PWM){
        pwm = MIN_PWM;
    }
//    pwmʱ���ڷ�Χ��
//    ���Խ���ϵ��
    pwm*=direction;
    if(pwm>0){
//ǰ
    HAL_GPIO_WritePin(this->gpioA, this->portA, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(this->gpioB, this->portB, GPIO_PIN_SET);
    } else if(pwm<0){
//��
    HAL_GPIO_WritePin(this->gpioA, this->portA, GPIO_PIN_SET);
    HAL_GPIO_WritePin(this->gpioB, this->portB, GPIO_PIN_RESET);
    }

    // �ٶ�pwm
    __HAL_TIM_SET_COMPARE(this->htim, this->channel, abs(pwm));
}



