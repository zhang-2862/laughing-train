#include <iostream>

int main() {
    int x,n;
    int s=0;
    scanf("%d%d",&x,&n);
    for(int i=0;i<n;++i){
        if(x!=6 && x!=7) {
            s += 250;
        }
        if(x==7){
            x=1;
        } else{
            ++x;
        }
    }
    printf("%d",s);
    return 0;
}

//#include <iostream>
//using namespace std;
//
//int main(int argc, char** argv)
//{
//    int x, n;
//    cin >> x >> n;
//    int d = n / 7 * 5; // 整周的工作日数
//    int r = n % 7;
//    if (r > 0) // 有剩余天数
//    {
//        if (r + x == 7 || x == 7) //如开始为周日肯定只休息一天；如r+x==7即最后一天为周六，也休息一天
//            r -= 1;
//        else if (r + x >= 8) //最后一天已过周日，休息两天
//            r -= 2;
//    }
//    cout << (d + r) * 250 << endl;
//    return 0;
//}
