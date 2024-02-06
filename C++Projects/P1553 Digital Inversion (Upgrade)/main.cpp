#include <iostream>

using namespace std;

int flag=0;//用来作为不同类型的标志

string inversion(string x) {
    int i;
    string y;
    string z;
    //确定从末尾开始第一个非0元素的位置
    for (i = x.length()-1; i >-1 ; --i) {
        if(x[i]!='0'){
            y=string(x,0,i+1);//从字符串str_x第0个字符开始，拷贝i个字符到str_y中
            break;
        }
    }
    z=y;
    if(flag==1){//确定从首部开始第一个非零元素的位置
        for (int j = 0; j < y.length() ; ++j) {
            if(x[j]!='0'){
                z=string(y,j,y.length()-j);//从字符串str_y第j个字符开始，拷贝length-j个字符到str_z中
                i=z.length()-1;//更新字符末尾位置
                break;
            }
        }
    }
    if(i==-1){
        z="0";
    }
    //字符串元素原地逆置
    for (int j=0; j<i ; --i,++j) {
        char temp=z[j];
        z[j]=z[i];
        z[i]=temp;
    }
    return z;
}

int main() {
    string str;
    string str1;
    string str2;
    cin>>str;
    int i;
    //求出’/‘和'.'符号的位置
    for (i = 0; i < str.length(); ++i) {
        if(str[i]=='.'){
            flag=1;//str为小数或者分数的情况
            break;
        }
        if(str[i]=='/'){
            flag=2;
            break;
        }
    }
    if(str[str.length()-1]=='%'){
        i=str.length()-1;//将倒数第一个数字元素位置赋给i
        flag=3;//str为百分数的情况
    }
    switch (flag) {
        case 0:
            str= inversion(str);
            cout<<str;
            break;
        case 1:
        case 2://小数或者分数的情况
            str2=string (str,i+1);// 从字符串str第i+1个字符开始到结束，拷贝到str2中
            str1=string (str,0,i);
            str1= inversion(str1);
            str2= inversion(str2);
            if(str[i]=='.'){
                cout<<str1<<'.'<<str2;
            }
            if(str[i]=='/'){
                cout<<str1<<'/'<<str2;
            }
            break;
        default:
            str1=string (str,0,i);
            str= inversion(str1);
            cout<<str<<'%'<<endl;
            break;
    }

    return 0;
}
