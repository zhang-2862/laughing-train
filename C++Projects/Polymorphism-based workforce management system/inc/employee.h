//
// Created by 28627 on 2024/3/22.
//

#ifndef POLYMORPHISM_BASED_WORKFORCE_MANAGEMENT_SYSTEM_EMPLOYEE_H
#define POLYMORPHISM_BASED_WORKFORCE_MANAGEMENT_SYSTEM_EMPLOYEE_H
#include <iostream>
#include "worker.h"

using namespace std;

class Employee :public Worker{
public:
    //构造函数
    Employee(int id,string name,int dId);
    //显示个人信息
    virtual void showInfo();
    //获取岗位名称
    virtual string getDeptName();
};
#endif //POLYMORPHISM_BASED_WORKFORCE_MANAGEMENT_SYSTEM_EMPLOYEE_H
