//
// Created by 28627 on 2024/3/23.
//
#include "../inc/manager.h"

//���캯��
Manager::Manager(int id,string name, int dId){
    this->m_Id=id;
    this->m_Name=name;
    this->m_DeptId=dId;
}
//��ʾ������Ϣ
void Manager:: showInfo(){
    cout<<"ְ����ţ� "<<this->m_Id
        <<"\tְ�������� "<<this->m_Name
        <<"\t��λ�� "<<this->getDeptName()
        <<"\t��λְ�� ����ϰ彻�������񣬲����·������Ա��"<<endl;

}
//��ȡ��λ����
string Manager:: getDeptName(){
    return string ("����");
}
