#include <iostream>
#include <string>

#define MAX 1000
using namespace std;

//��ϵ�˽ṹ��
struct Person{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_phone;
    string m_Addr;
};

//ͨѶ¼�ṹ��
struct AddressBooks{
    //ͨѶ¼�б������ϵ������
    struct Person personArray[MAX];

    //ͨѶ¼�е�ǰ��¼��ϵ�˸���
    int m_Size;

};

//1�������ϵ��
void addPerson(AddressBooks *abs){
    //�ж�ͨѶ¼�Ƿ����������˲������
    if(abs->m_Size==MAX){
        cout<<"ͨѶ¼�������޷���ӣ�"<<endl;
        return;
    } else{
        //��Ӿ�����ϵ��

        //����
        string name;
        cout<<"������������ "<<endl;
        cin>>name;
        abs->personArray[abs->m_Size].m_Name=name;

        //�Ա�
        cout<<"�������Ա� "<<endl;
        cout<<"1 --- ��"<<endl;
        cout<<"2 --- Ů"<<endl;
        int sex=0;
        while (true){
            //����������1��2�����˳�ѭ����������������
            cin>>sex;
            if(sex==1||sex==2){
                abs->personArray[abs->m_Size].m_Sex=sex;
                break;
            }
            cout<<"������������������!"<<endl;
        }

        //����
        cout<<"���������䣺 "<<endl;
        int age=0;
        cin>>age;
        abs->personArray[abs->m_Size].m_Age=age;

        //�绰
        cout<<"��������ϵ�绰�� "<<endl;
        string phone;
        cin>> phone;
        abs->personArray[abs->m_Size].m_phone=phone;

        //סַ
        cout<<"�������ͥ��ַ�� "<<endl;
        string address;
        cin>> address;
        abs->personArray[abs->m_Size].m_Addr=address;

        //����ͨѶ¼����
        abs->m_Size++;

        cout<<"��ӳɹ�"<<endl;


    }
}

//2����ʾ������ϵ��
void showPerson(AddressBooks *abs){
    //�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ��
    //�����Ϊ0����ʾ��¼����ϵ����Ϣ
    if (abs->m_Size == 0){
        cout<<"��ǰ��¼Ϊ��"<<endl;
    } else{
        for (int i = 0; i < abs->m_Size; ++i) {
            cout<<"������ "<<abs->personArray[i].m_Name<<"\t";
            cout<<"�Ա� "<<(abs->personArray[i].m_Sex == 1 ?"��":"Ů")<<"\t";
            cout<<"���䣺 "<<abs->personArray[i].m_Age<<"\t";
            cout<<"�绰�� "<<abs->personArray[i].m_phone<<"\t";
            cout<<"סַ�� "<<abs->personArray[i].m_Addr<<endl;
        }
    }
}
//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
int isExist(AddressBooks * abs,string name){
    for (int i = 0; i < abs->m_Size; ++i) {
        if(abs->personArray[i].m_Name==name){
            return i;//�ҵ��򷵻������±�
        } else{
            return -1;//δ�ҵ��򷵻�-1��
        }
    }
}

//3��ɾ��ָ����ϵ��
void deletePerson(AddressBooks *abs){
    cout << "��������Ҫɾ������ϵ��"<<endl;

    string name;
    cin>> name;

    int ret = isExist(abs,name);

    if(ret!=-1){
        for (int i = ret; i < abs->m_Size; ++i) {
            //����Ǩ��
            abs->personArray[i]=abs->personArray[i+1];
        }
        abs->m_Size--;//����ͨѶ¼�е���Ա��
    }else{
        cout<<"���޴���"<<endl;
    }
}

//4������ָ����ϵ��
void findPerson(AddressBooks *abs){
    cout<<"��������Ҫ���ҵ���ϵ��"<<endl;
    string name;
    cin>> name;

    //�ж�ָ������ϵ���Ƿ���ͨѶ¼��
    int ret= isExist(abs,name);

    if(ret!=-1){
        cout<<"������ "<<abs->personArray[ret].m_Name<<"\t";
        cout<<"�Ա� "<<(abs->personArray[ret].m_Sex == 1 ?"��":"Ů")<<"\t";
        cout<<"���䣺 "<<abs->personArray[ret].m_Age<<"\t";
        cout<<"�绰�� "<<abs->personArray[ret].m_phone<<"\t";
        cout<<"סַ�� "<<abs->personArray[ret].m_Addr<<endl;
    } else{
        cout<<"���޴���"<<endl;
    }
}

//5���޸�ָ����ϵ����Ϣ
void modifyPerson(AddressBooks *abs){
    cout<<"��������Ҫ�޸ĵ���ϵ��"<<endl;
    string name;
    cin>>name;

    int ret= isExist(abs,name);
    if(ret!=-1){
        string name;
        cout<<"������������ "<<endl;
        cin>>name;
        abs->personArray[ret].m_Name=name;
        cout<<"�������Ա� "<<endl;
        cout<<"1 --- �� "<<endl;
        cout<<"2 --- Ů�� "<<endl;
        int sex =0;
        while (true){
            cin>> sex;
            if(sex==1 ||sex ==2 ){
                //������ȷ �˳�ѭ��
                abs->personArray[ret].m_Sex=sex;
                break;
            }
            cout <<"������������������"<<endl;
        }
        //����
        cout <<"���������䣺 "<<endl;
        int age=0;
        cin>> age;
        abs->personArray[ret].m_Age=age;

        //�绰
        cout <<"��������ϵ�绰�� "<<endl;
        string phone;
        cin>> phone;
        abs->personArray[ret].m_phone=phone;

        //��ַ
        cout <<"�������ͥסַ�� "<<endl;
        string address;
        cin>> address;
        abs->personArray[ret].m_Addr=address;

        cout <<"�޸ĳɹ�!"<<endl;

    } else{
        cout<<"���޴���"<<endl;
    }
}

//6�����������ϵ��
void cleanPerson(AddressBooks *abs){
    abs->m_Size=0;//����ǰ��¼��ϵ��������Ϊ0�����߼���ղ���
    cout<<"ͨѶ¼�����"<<endl;
}



void showMenu(){
    cout<<"***********************"<<endl;
    cout<<"***** 1�������ϵ�� *****"<<endl;
    cout<<"***** 2����ʾ��ϵ�� *****"<<endl;
    cout<<"***** 3��ɾ����ϵ�� *****"<<endl;
    cout<<"***** 4��������ϵ�� *****"<<endl;
    cout<<"***** 5���޸���ϵ�� *****"<<endl;
    cout<<"***** 6�������ϵ�� *****"<<endl;
    cout<<"***** 0���˳�ͨѶ¼ *****"<<endl;
    cout<<"***********************"<<endl;

}

int main() {
    //����ͨѶ¼�ṹ�����
    AddressBooks abs;
    //��ʼ��ͨѶ¼�е�ǰ��Ա����
    abs.m_Size=0;

    int select=0;//�����û�ѡ������ı���



    while (true) {
        showMenu();
        cin >> select;
        switch (select) {
            case 1:// ���
                addPerson(&abs);
                break;
            case 2:// ��ʾ
                showPerson(&abs);
                break;
            case 3:// ɾ��
                deletePerson(&abs);
                break;
            case 4:// ����
                findPerson(&abs);
                break;
            case 5:// �޸�
                modifyPerson(&abs);
                break;
            case 6:// ���
                cleanPerson(&abs);
                break;
            case 0:// �˳�
                cout << "��ӭ�´�ʹ��" << endl;
                return 0;
                break;
            default:
                break;
        }
    }

}
