#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//二进制文件 写文件

class Person{
public:
    char m_Name[64];
    int m_Age;
};

void test01(){
    //1、包含头文件
    //2、创建流对象
    ofstream ofs("C:\\Users\\Zhang_2862\\Desktop\\testB.txt",ios::out|ios::binary);

    //3、打开文件
//    ofs.open("C:\\Users\\Zhang_2862\\Desktop\\testB.txt",ios::out|ios::binary);
    //4、写文件
    Person p={"张三",18};
    ofs.write((const char *)&p,sizeof (Person));
    //5、关闭文件
    ofs.close();
}

int main() {

    test01();
    return 0;
}
