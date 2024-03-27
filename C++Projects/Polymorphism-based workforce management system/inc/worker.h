//
// Created by 28627 on 2024/3/22.
//

#ifndef POLYMORPHISM_BASED_WORKFORCE_MANAGEMENT_SYSTEM_WORKER_H
#define POLYMORPHISM_BASED_WORKFORCE_MANAGEMENT_SYSTEM_WORKER_H

#include <iostream>
#include <string>

using namespace std;
//ְ��������
class Worker{
public:
    //��ʾ������Ϣ
    virtual void showInfo()=0;
    //��ȡ��λ����
    virtual string getDeptName()=0;

    int m_Id;//ְ�����
    string m_Name;//ְ������
    int m_DeptId;//ְ�����ڲ������Ʊ��
};
#endif //POLYMORPHISM_BASED_WORKFORCE_MANAGEMENT_SYSTEM_WORKER_H
