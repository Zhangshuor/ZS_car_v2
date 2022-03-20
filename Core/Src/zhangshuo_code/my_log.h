//
// Created by 29976 on 2022/3/19.
//

#ifndef ZS_CAR_V2_MY_LOG_H
#define ZS_CAR_V2_MY_LOG_H

#define LOG_ENABLE 1
#if LOG_ENABLE
#define mylog(format,...) printf(format"\r\n",##__VA_ARGS__)
#else
#define mylog(format,...)
#endif

#endif //ZS_CAR_V2_MY_LOG_H
