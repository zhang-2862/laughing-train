//
// Created by 28627 on 2024/3/23.
//

#ifndef POLYMORPHISM_BASED_WORKFORCE_MANAGEMENT_SYSTEM_BOSS_H
#define POLYMORPHISM_BASED_WORKFORCE_MANAGEMENT_SYSTEM_BOSS_H
#include <iostream>

using namespace std;
#include "worker.h"

//经理类
class  Boss:public Worker{
public:
    //构造函数
    Boss(int id,string name, int dId);
    //显示个人信息
    virtual void showInfo();
    //获取岗位名称
    virtual string getDeptName();
};
#endif //POLYMORPHISM_BASED_WORKFORCE_MANAGEMENT_SYSTEM_BOSS_H
