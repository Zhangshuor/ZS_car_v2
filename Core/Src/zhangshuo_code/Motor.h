/********************************************************************************
* @author: ��˶
* @email: 2997605195@qq.com
* @date: 3.19
* @version: 1.0
* @description: �����ͷ�ļ������������͵���ĳ�ʼ����ת����������
********************************************************************************/

#ifndef ZS_CAR_V2_MOTOR_H
#define ZS_CAR_V2_MOTOR_H

#include "tim.h"
#include "config.h"
#include "math.h"

// ���
// ���ԣ���ʱ�� CHANNEL ��һ��GPIO ��һ��GPIO��� �ڶ���GPIO �ڶ���GPIO���
// ��Ϊ�����ת��
class Motor {
private:
    // ��ʱ��
    TIM_HandleTypeDef *htim;
    // channel
    uint32_t channel;
    //GPIOA
    GPIO_TypeDef *gpioA;
    uint16_t portA;
    //GPIOB
    GPIO_TypeDef *gpioB;
    uint16_t portB;
    //������� Ҫô��1 Ҫô-1
    int direction = 1;
public:
    Motor(TIM_HandleTypeDef *htim, uint32_t channel, GPIO_TypeDef *gpioA, uint16_t portA, GPIO_TypeDef *gpioB,
          uint16_t portB,int direction);

    ~Motor();
    // ��ʼ����������һЩ�����Ĳ���
    void init();
//�������ת���ĺ���
    void spin(int pwm);


};


#endif //ZS_CAR_V2_MOTOR_H
