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
    //���캯��
    WorkerManager();

    //չʾ�˵�
    void Show_Menu();
    //�˳�ϵͳ
    void ExitSystem();

    //��¼ְ������
    int m_EmpNum;

    //ְ������ָ��
    Worker ** m_EmpArray;

    //���ְ��
    void Add_Emp();

    //�����ļ�
    void Save();

    //�ж��ļ��Ƿ�Ϊ�� ��־
    bool m_FileIsEmpty;

    //ͳ���ļ�������
    int get_EmpNum();

    //��ʼ��Ա��
    void init_Emp();

    //��ʾְ��
    void Show_Emp();

    //��������
    ~WorkerManager();
};
#endif //POLYMORPHISM_BASED_WORKFORCE_MANAGEMENT_SYSTEM_WORKERMANAGER_H
