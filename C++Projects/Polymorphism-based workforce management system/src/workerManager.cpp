//
// Created by 28627 on 2024/3/22.
//
#include "../inc/workerManager.h"

WorkerManager::WorkerManager() {
    //1���ļ�������

    ifstream ifs;
    ifs.open(FILENAME,ios::in);//���ļ�

    if(!ifs.is_open()){
//        cout<<"�ļ�������"<<endl;
        //��ʼ������
        //��ʼ����¼����
        this->m_EmpNum=0;
        //��ʼ������ָ��
        this->m_EmpArray=NULL;
        //��ʼ���ļ��Ƿ�Ϊ��
        this->m_FileIsEmpty= true;
        ifs.close();
        return;
    }

    //2���ļ����� ������Ϊ��
    char ch;
    ifs>>ch;//ȡ��һ���ַ������ļ�Ϊ����ֻ��һ��EOF��־��
    if(ifs.eof()){//��־Ϊ������г�ʼ��
//        //�ļ�Ϊ��
//        cout<<"�ļ�Ϊ�գ�"<<endl;
        //��ʼ����¼����
        this->m_EmpNum=0;
        //��ʼ������ָ��
        this->m_EmpArray=NULL;
        //��ʼ���ļ��Ƿ�Ϊ��
        this->m_FileIsEmpty= true;
        ifs.close();
        return;
    }

    //3���ļ����ڣ����Ҽ�¼����
    int num= this->get_EmpNum();
    cout<<"ְ������Ϊ�� "<<num<<endl;
    this->m_EmpNum=num;

    //���ٿռ�
    this->m_EmpArray=new Worker*[this->m_EmpNum];
    //���ļ��е����ݣ��浽������
    this->init_Emp();
    this->m_FileIsEmpty= false;
}

//չʾ�˵�
void WorkerManager::Show_Menu() {
    cout<<"**************************************"<<endl;
    cout<<"*******    ��ӭʹ��ְ������ϵͳ    ******"<<endl;
    cout<<"**********   0.�˳��������   **********"<<endl;
    cout<<"**********   1.����ְ����Ϣ   **********"<<endl;
    cout<<"**********   2.��ʾְ����Ϣ   **********"<<endl;
    cout<<"**********   3.ɾ����ְְ��   **********"<<endl;
    cout<<"**********   4.�޸�ְ����Ϣ   **********"<<endl;
    cout<<"**********   5.����ְ����Ϣ   **********"<<endl;
    cout<<"**********   6.���ձ������   **********"<<endl;
    cout<<"**********   7.��������ĵ�   **********"<<endl;
    cout<<"**************************************"<<endl;
}
//�˳�ϵͳ
void WorkerManager::ExitSystem(){
    cout<<"��ӭ�´�ʹ��"<<endl;
    exit(0);//�˳�����

}
//���ְ��
void WorkerManager::Add_Emp() {
    cout<<"���������ְ�������� "<<endl;

    int addNum=0;//�����û�����������
    cin>> addNum;
    if(addNum>0){
        //���
        //��������¿ռ��С
        int newSize=this->m_EmpNum+addNum;//�¿ռ����ԭ��С������

        //�����¿ռ�
        Worker ** newSpace=new Worker*[newSize];

        //��ԭ���ռ������ݿ������¿ռ���
        if(this->m_EmpArray!=NULL){
            for (int i = 0; i < this->m_EmpNum; ++i) {
                newSpace[i]= this->m_EmpArray[i];
            }
        }
        //�������������
        for (int i = 0; i < addNum; ++i) {
            int id; //ְ�����
            string name; //ְ������
            int dSelect; //����ѡ��

            cout<<"������� "<<i+1<<"����ְ����ţ� "<<endl;
            cin>>id;

            cout<<"������� "<<i+1<<"����ְ�������� "<<endl;
            cin>>name;

            cout<<"��ѡ���ְ����λ�� "<<endl;
            cout<<"1����ְͨ��"<<endl;
            cout<<"2������"<<endl;
            cout<<"3���ϰ�"<<endl;
            cin>>dSelect;

            Worker * worker=NULL;
            switch (dSelect) {
                case 1:
                    worker = new Employee(id,name,1);
                    break;
                case 2:
                    worker = new Manager(id,name,2);
                    break;
                case 3:
                    worker = new Boss(id,name,3);
                    break;
                default:
                    break;

            }
            // ������ְ��ְ�𣬱��浽������
            newSpace[this->m_EmpNum+i]=worker;

        }
        //�ͷ�ԭ�пռ�
        delete[] this->m_EmpArray;

        //�����¿ռ��ָ��
        this->m_EmpArray=newSpace;

        //����ְ������
        this->m_EmpNum=newSize;

        //����ְ����Ϊ�ձ�־
        this->m_FileIsEmpty= false;

        //��ʾ��ӳɹ�
        cout<<"�ɹ����"<<addNum<<"����ְ����"<<endl;

        //�������ݵ��ļ���
        this->Save();

    } else{
        cout<<"��������"<<endl;
    }
}

//�����ļ�
void WorkerManager::Save() {
     ofstream ofs;
     ofs.open(FILENAME,ios::out);//������ķ�ʽ���ļ�--д�ļ�

     //��ÿ��������д�뵽�ļ���
    for (int i = 0; i < this->m_EmpNum; ++i) {
        ofs<<this->m_EmpArray[i]->m_Id<<" "
           <<this->m_EmpArray[i]->m_Name<<" "
           <<this->m_EmpArray[i]->m_DeptId<<endl;
    }

    //�ر��ļ�
    ofs.close();
}

//ͳ���ļ�������
int WorkerManager::get_EmpNum() {
    ifstream ifs;
    ifs.open(FILENAME,ios::in);//���ļ� ��

    int id;
    string name;
    int dId;

    int num=0;
    while (ifs>>id && ifs>>name && ifs>>dId){
        num++;//ͳ����������
    }
    return num;
}

//��ʼ��Ա��
void WorkerManager::init_Emp() {
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    int id;
    string name;
    int dId;

    int index=0;
    while (ifs>>id && ifs>>name && ifs>>dId ){
        Worker * worker=NULL;

        if(dId==1){//��ͨԱ��
            worker=new Employee(id,name,dId);
        }
        else if(dId==2){//����
            worker=new Manager(id,name,dId);
        }
        else{//�ϰ�
            worker=new Boss(id,name,dId);
        }
        this->m_EmpArray[index++]=worker;
    }

    //�ر��ļ�
    ifs.close();
}
//��ʾְ��
void WorkerManager::Show_Emp() {
    //�ж��ļ��Ƿ�Ϊ��
    if(this->m_FileIsEmpty){
        cout<<"�ļ������ڻ��¼Ϊ�գ�"<<endl;
    } else{
        for (int i = 0; i < m_EmpNum; ++i) {
            //���ö�̬���ó���ӿ�
            this->m_EmpArray[i]->showInfo();
        }
    }
}

WorkerManager::~WorkerManager() {
    if(this->m_EmpArray!=NULL){
        delete[] this->m_EmpArray;
        this->m_EmpArray=NULL;
    }
}





