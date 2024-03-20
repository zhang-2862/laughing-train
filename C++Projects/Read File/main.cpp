#include <iostream>
#include <string>
using namespace std;
#include <fstream>

void test01(){
    //1、包含头文件

    //2、创建流对象
    ifstream ifs;

    //3、打开文件 并且判断是否打开成功
    ifs.open("C:\\Users\\Zhang_2862\\Desktop\\test.txt",ios::in);

    if(!ifs.is_open()){
        cout<<"打开文件失败"<<endl;
    }
    //4、读数据

    //第一种读取方法
    char buf[1024]={0};
//    while (ifs>>buf){
//        cout<<buf<<endl;
//    }

    //第二种读取方法
//    while (ifs.getline(buf,sizeof (buf))){
//        cout<<buf<<endl;
//    }

    //第三种读取方法
//    string buffer;
//    while(getline(ifs,buffer)){
//        cout<<buffer<<endl;
//    }

    //第四种读取方法
    char c;
    while ((c=ifs.get())!=EOF){
        cout<<c;
    }
    //5、关闭文件
    ifs.close();
}

int main() {
    test01();
    return 0;
}
