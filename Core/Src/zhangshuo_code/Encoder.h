/********************************************************************************
* @author: 张硕
* @email: 2997605195@qq.com
* @date: ${DATE} ${TIME}
* @version: 1.0
* @description: 编码器的头文件
********************************************************************************/

#ifndef ZS_CAR_V2_ENCODER_H
#define ZS_CAR_V2_ENCODER_H

#include "tim.h"

//编码器
//属性：定时器 channel
//行为：初始化，获取当前数据

class Encoder {
private:
    // 编码器
    TIM_HandleTypeDef *htim;
    // channel
    uint32_t channel;
    int direction=1;


public:
    Encoder(TIM_HandleTypeDef *htim,uint32_t channel,int direction);

    ~Encoder();

    //初始化
    void init();
    // 读取编码器数据(short类型进行接收)
    short read();

};


#endif //ZS_CAR_V2_ENCODER_H
