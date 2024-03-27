//
// Created by 28627 on 2024/3/22.
//

#ifndef POLYMORPHISM_BASED_WORKFORCE_MANAGEMENT_SYSTEM_WORKERMANAGER_H
#define POLYMORPHISM_BASED_WORKFORCE_MANAGEMENT_SYSTEM_WORKERMANAGER_H

#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
#define FILENAME "empFile.t"

using namespace std;
class WorkerManager{
public:
    //构造函数
    WorkerManager();

    //展示菜单
    void Show_Menu();
    //退出系统
    void ExitSystem();

    //记录职工人数
    int m_EmpNum;

    //职工数组指针
    Worker ** m_EmpArray;

    //添加职工
    void Add_Emp();

    //保存文件
    void Save();

    //判断文件是否为空 标志
    bool m_FileIsEmpty;

    //统计文件中人数
    int get_EmpNum();

    //初始化员工
    void init_Emp();

    //显示职工
    void Show_Emp();

    //析构函数
    ~WorkerManager();
};
#endif //POLYMORPHISM_BASED_WORKFORCE_MANAGEMENT_SYSTEM_WORKERMANAGER_H
