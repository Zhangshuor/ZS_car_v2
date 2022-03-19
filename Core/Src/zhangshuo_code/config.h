/********************************************************************************
* @author: 张硕
* @email: 2997605195@qq.com
* @date: ${DATE} ${TIME}
* @version: 1.0
* @description: 事先准备好的宏定义配置文件
********************************************************************************/

#ifndef CAR_CONFIG_H
#define CAR_CONFIG_H
//最大和最小PWM
#define MAX_PWM         7200
#define MIN_PWM         -7200
//编码器获取数据的频率
#define MOVE_CTRL_RATE 100

// 轮子转一圈的信号数
#define WHEEL_TPR           (13 * 30 * 4)
// 轮子的直径
#define WHEEL_DIAMETER      0.064f
// 左右轮子的距离
#define WHEEL_DISTANCE      0.155f
// 前后轮子的轴距
#define WHEEL_AXIS          0.1445f

#endif //CAR_CONFIG_H
