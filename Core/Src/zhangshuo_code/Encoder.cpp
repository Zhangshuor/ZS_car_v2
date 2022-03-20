//
// Created by zhangshuo on 2022/3/19.
//

#include "Encoder.h"

Encoder::Encoder(TIM_HandleTypeDef *htim, uint32_t channel, int direction) {
    this->htim = htim;
    this->channel = channel;
    this->direction = direction;

}

Encoder::~Encoder() {

}
/********************************************************************************
* @author: 张硕
* @params: none
* @return: none
* @description: 对编码器进行初始化
********************************************************************************/

void Encoder::init() {
    //开启定时器
    HAL_TIM_Encoder_Start(this->htim,this->channel);
    //清空定时器
    __HAL_TIM_SET_COUNTER(this->htim,0);

}
/********************************************************************************
* @author: 张硕
* @params: none
* @return: c_nums:编码器圈数
* @description: 读取编码器的数据（圈数）
********************************************************************************/

short Encoder::read() {
    // 获取的编码器数据
    short i = __HAL_TIM_GET_COUNTER(this->htim);
    //重置计数
    __HAL_TIM_SET_COUNTER(this->htim,0);
    return i*this->direction;
}
