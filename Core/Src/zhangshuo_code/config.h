/********************************************************************************
* @author: ��˶
* @email: 2997605195@qq.com
* @date: ${DATE} ${TIME}
* @version: 1.0
* @description: ����׼���õĺ궨�������ļ�
********************************************************************************/

#ifndef CAR_CONFIG_H
#define CAR_CONFIG_H
//������СPWM
#define MAX_PWM         7200
#define MIN_PWM         -7200
//��������ȡ���ݵ�Ƶ��
#define MOVE_CTRL_RATE 100

// ����תһȦ���ź���
#define WHEEL_TPR           (13 * 30 * 4)
// ���ӵ�ֱ��
#define WHEEL_DIAMETER      0.064f
// �������ӵľ���
#define WHEEL_DISTANCE      0.155f
// ǰ�����ӵ����
#define WHEEL_AXIS          0.1445f

#endif //CAR_CONFIG_H
