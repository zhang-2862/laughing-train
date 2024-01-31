#include<iostream>
#include <math.h>
// 填上你觉得需要的其他头文件
using namespace std;
int main() {
    int T;
    cin >> T;
    if (T == 1) {
        // 粘贴问题 1 的主函数代码，除了 return 0
        cout << "I love Luogu!";
    } else if (T == 2) {
        // 粘贴问题 2 的主函数代码，除了 return 0
        cout << 2 + 4 << " " << 10 - 2 - 4;
    } else if (T == 3) {
        // 请自行完成问题 3 的代码
        cout <<14/4<<endl<<4*(14/4)<<endl<<14-4*(14/4);
    } else if (T == 4) {
        // 请自行完成问题 4 的代码
        double a=500;
        double ret=500/3.0;
        printf("%6.3lf",ret);
    } else if (T == 5) {
        // 请自行完成问题 5 的代码
        int la=260;
        int lb=220;
        int va=12;
        int vb=20;
        printf("%d",(la+lb)/(va+vb));
    } else if (T == 6) {
        // 请自行完成问题 6 的代码
        cout<<sqrt(6*6+9*9);
    } else if (T == 7) {
        // 请自行完成问题 7 的代码
        printf("%d\n",110);
        printf("%d\n",90);
        printf("%d\n",0);
    } else if (T == 8) {
        // 请自行完成问题 8 的代码
        const double pi=3.141593;
        cout<<pi*10<<endl<<pi*25<<endl<<4.0/3*pi*125<<endl;
    } else if (T == 9) {
        // 请自行完成问题 9 的代码
        int n=1;//桃子总数
        int a,b,c;//第一天，第二天，第三天吃的桃子数
        for (int i = 0; i < 3; ++i) {
            n=(n+1)*2;
        }
        printf("%d",n);
    } else if (T == 10) {
        // 请自行完成问题 10 的代码
        float i;
        i=180.0/24;
        int s;
        s=60-i*6;
        int res=((10*i+s)/10);
        printf("%d",res);

    } else if (T == 11) {
        // 请自行完成问题 11 的代码
        cout<<1.0*100/3;
    } else if (T == 12) {
        // 请自行完成问题 12 的代码
        char c;
        c='M';
        printf("%d\n",c-'A'+1);
        printf("%c\n",'A'+17);
    } else if (T == 13) {
        // 请自行完成问题 13 的代码
        const double pi=3.141593;
        cout<<(int)(pow(4.0/3*pi*(4*4*4+10*10*10),1.0/3));
    } else if (T == 14) {
        // 请自行完成问题 14 的代码
        int sum=0;
        int price=110;
        int people=10;
        for (int i = 110; i >0 ; --i) {
            if((110-i)*(10+i)>=3500){
                printf("%d",price-i);
                break;
            }
        }
    }
    return 0;
}
