#include <iostream>
#include <string>
using namespace std;
#include <fstream>

void test01(){
    //1������ͷ�ļ�

    //2������������
    ifstream ifs;

    //3�����ļ� �����ж��Ƿ�򿪳ɹ�
    ifs.open("C:\\Users\\Zhang_2862\\Desktop\\test.txt",ios::in);

    if(!ifs.is_open()){
        cout<<"���ļ�ʧ��"<<endl;
    }
    //4��������

    //��һ�ֶ�ȡ����
    char buf[1024]={0};
//    while (ifs>>buf){
//        cout<<buf<<endl;
//    }

    //�ڶ��ֶ�ȡ����
//    while (ifs.getline(buf,sizeof (buf))){
//        cout<<buf<<endl;
//    }

    //�����ֶ�ȡ����
//    string buffer;
//    while(getline(ifs,buffer)){
//        cout<<buffer<<endl;
//    }

    //�����ֶ�ȡ����
    char c;
    while ((c=ifs.get())!=EOF){
        cout<<c;
    }
    //5���ر��ļ�
    ifs.close();
}

int main() {
    test01();
    return 0;
}
