#include <iostream>
#include <string>

#define MAX 1000
using namespace std;

//联系人结构体
struct Person{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_phone;
    string m_Addr;
};

//通讯录结构体
struct AddressBooks{
    //通讯录中保存的联系人数组
    struct Person personArray[MAX];

    //通讯录中当前记录联系人个数
    int m_Size;

};

//1、添加联系人
void addPerson(AddressBooks *abs){
    //判断通讯录是否已满，满了不可添加
    if(abs->m_Size==MAX){
        cout<<"通讯录已满，无法添加！"<<endl;
        return;
    } else{
        //添加具体联系人

        //姓名
        string name;
        cout<<"请输入姓名： "<<endl;
        cin>>name;
        abs->personArray[abs->m_Size].m_Name=name;

        //性别
        cout<<"请输入性别： "<<endl;
        cout<<"1 --- 男"<<endl;
        cout<<"2 --- 女"<<endl;
        int sex=0;
        while (true){
            //如果输入的是1或2可以退出循环，否则重新输入
            cin>>sex;
            if(sex==1||sex==2){
                abs->personArray[abs->m_Size].m_Sex=sex;
                break;
            }
            cout<<"输入有误，请重新输入!"<<endl;
        }

        //年龄
        cout<<"请输入年龄： "<<endl;
        int age=0;
        cin>>age;
        abs->personArray[abs->m_Size].m_Age=age;

        //电话
        cout<<"请输入联系电话： "<<endl;
        string phone;
        cin>> phone;
        abs->personArray[abs->m_Size].m_phone=phone;

        //住址
        cout<<"请输入家庭地址： "<<endl;
        string address;
        cin>> address;
        abs->personArray[abs->m_Size].m_Addr=address;

        //更新通讯录人数
        abs->m_Size++;

        cout<<"添加成功"<<endl;


    }
}

//2、显示所有联系人
void showPerson(AddressBooks *abs){
    //判断通讯录中人数是否为0，如果为0，提示记录为空
    //如果不为0，显示记录的联系人信息
    if (abs->m_Size == 0){
        cout<<"当前记录为空"<<endl;
    } else{
        for (int i = 0; i < abs->m_Size; ++i) {
            cout<<"姓名： "<<abs->personArray[i].m_Name<<"\t";
            cout<<"性别： "<<(abs->personArray[i].m_Sex == 1 ?"男":"女")<<"\t";
            cout<<"年龄： "<<abs->personArray[i].m_Age<<"\t";
            cout<<"电话： "<<abs->personArray[i].m_phone<<"\t";
            cout<<"住址： "<<abs->personArray[i].m_Addr<<endl;
        }
    }
}
//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
int isExist(AddressBooks * abs,string name){
    for (int i = 0; i < abs->m_Size; ++i) {
        if(abs->personArray[i].m_Name==name){
            return i;//找到则返回数组下标
        } else{
            return -1;//未找到则返回-1；
        }
    }
}

//3、删除指定联系人
void deletePerson(AddressBooks *abs){
    cout << "请输入您要删除的联系人"<<endl;

    string name;
    cin>> name;

    int ret = isExist(abs,name);

    if(ret!=-1){
        for (int i = ret; i < abs->m_Size; ++i) {
            //数据迁移
            abs->personArray[i]=abs->personArray[i+1];
        }
        abs->m_Size--;//更新通讯录中的人员数
    }else{
        cout<<"查无此人"<<endl;
    }
}

//4、查找指定联系人
void findPerson(AddressBooks *abs){
    cout<<"请输入您要查找的联系人"<<endl;
    string name;
    cin>> name;

    //判断指定的联系人是否在通讯录中
    int ret= isExist(abs,name);

    if(ret!=-1){
        cout<<"姓名： "<<abs->personArray[ret].m_Name<<"\t";
        cout<<"性别： "<<(abs->personArray[ret].m_Sex == 1 ?"男":"女")<<"\t";
        cout<<"年龄： "<<abs->personArray[ret].m_Age<<"\t";
        cout<<"电话： "<<abs->personArray[ret].m_phone<<"\t";
        cout<<"住址： "<<abs->personArray[ret].m_Addr<<endl;
    } else{
        cout<<"查无此人"<<endl;
    }
}

//5、修改指定联系人信息
void modifyPerson(AddressBooks *abs){
    cout<<"请输入您要修改的联系人"<<endl;
    string name;
    cin>>name;

    int ret= isExist(abs,name);
    if(ret!=-1){
        string name;
        cout<<"请输入姓名： "<<endl;
        cin>>name;
        abs->personArray[ret].m_Name=name;
        cout<<"请输入性别： "<<endl;
        cout<<"1 --- 男 "<<endl;
        cout<<"2 --- 女： "<<endl;
        int sex =0;
        while (true){
            cin>> sex;
            if(sex==1 ||sex ==2 ){
                //输入正确 退出循环
                abs->personArray[ret].m_Sex=sex;
                break;
            }
            cout <<"输入有误，请重新输入"<<endl;
        }
        //年龄
        cout <<"请输入年龄： "<<endl;
        int age=0;
        cin>> age;
        abs->personArray[ret].m_Age=age;

        //电话
        cout <<"请输入联系电话： "<<endl;
        string phone;
        cin>> phone;
        abs->personArray[ret].m_phone=phone;

        //地址
        cout <<"请输入家庭住址： "<<endl;
        string address;
        cin>> address;
        abs->personArray[ret].m_Addr=address;

        cout <<"修改成功!"<<endl;

    } else{
        cout<<"查无此人"<<endl;
    }
}

//6、清空所有联系人
void cleanPerson(AddressBooks *abs){
    abs->m_Size=0;//将当前记录联系人数量置为0，做逻辑清空操作
    cout<<"通讯录已清空"<<endl;
}



void showMenu(){
    cout<<"***********************"<<endl;
    cout<<"***** 1、添加联系人 *****"<<endl;
    cout<<"***** 2、显示联系人 *****"<<endl;
    cout<<"***** 3、删除联系人 *****"<<endl;
    cout<<"***** 4、查找联系人 *****"<<endl;
    cout<<"***** 5、修改联系人 *****"<<endl;
    cout<<"***** 6、清空联系人 *****"<<endl;
    cout<<"***** 0、退出通讯录 *****"<<endl;
    cout<<"***********************"<<endl;

}

int main() {
    //创建通讯录结构体变量
    AddressBooks abs;
    //初始化通讯录中当前人员个数
    abs.m_Size=0;

    int select=0;//创建用户选择输入的变量



    while (true) {
        showMenu();
        cin >> select;
        switch (select) {
            case 1:// 添加
                addPerson(&abs);
                break;
            case 2:// 显示
                showPerson(&abs);
                break;
            case 3:// 删除
                deletePerson(&abs);
                break;
            case 4:// 查找
                findPerson(&abs);
                break;
            case 5:// 修改
                modifyPerson(&abs);
                break;
            case 6:// 清空
                cleanPerson(&abs);
                break;
            case 0:// 退出
                cout << "欢迎下次使用" << endl;
                return 0;
                break;
            default:
                break;
        }
    }

}
