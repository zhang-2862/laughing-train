#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//�������ļ� ���ļ�

class Person{
public:
    char m_Name[64];
    int m_Age;
};

void test01(){
    ifstream ifs;
    ifs.open("C:\\Users\\Zhang_2862\\Desktop\\testB.txt",ios::in|ios::binary);
    if(!ifs.is_open()){
        cout<<"���ļ�ʧ��"<<endl;
        return;
    }
    Person p;
    ifs.read((char *)&p, sizeof(Person));
    cout<<"������ "<<p.m_Name<<" ���䣺 "<<p.m_Age<<endl;
    ifs.close();
}
int main() {
    test01();
    return 0;
}
