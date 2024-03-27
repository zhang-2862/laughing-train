//
// Created by 28627 on 2024/3/22.
//

#ifndef POLYMORPHISM_BASED_WORKFORCE_MANAGEMENT_SYSTEM_WORKER_H
#define POLYMORPHISM_BASED_WORKFORCE_MANAGEMENT_SYSTEM_WORKER_H

#include <iostream>
#include <string>

using namespace std;
//职工抽象类
class Worker{
public:
    //显示个人信息
    virtual void showInfo()=0;
    //获取岗位名称
    virtual string getDeptName()=0;

    int m_Id;//职工编号
    string m_Name;//职工姓名
    int m_DeptId;//职工所在部门名称编号
};
#endif //POLYMORPHISM_BASED_WORKFORCE_MANAGEMENT_SYSTEM_WORKER_H
