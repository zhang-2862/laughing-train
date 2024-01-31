#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int pencil;
    int a;
    int b;
    int sum;
    int min=0;

    scanf("%d",&pencil);
    for (int i = 0; i < 3; ++i) {
        scanf("%d%d",&a,&b);
        if(pencil%a==0){
            sum=pencil/a*b;
        } else{
            sum=(pencil/a+1)*b;
        }
        if (min==0 || sum<min){
            min=sum;
        }
    }
    printf("%d",min);
}
//#include<cstdio>
//using namespace std;
//int i,j,k,n,m,w,ans;
//int main(){
//    scanf("%d",&n);
//    for(i=0;i<3;i++){
//        scanf("%d%d",&j,&k);m=j;w=k;//输入并存下初始的价格与数量
//        while(j<n){j<<=1;k<<=1;}//价格与数量不断*2直到数量大于n
//        while(j>n){j-=m;k-=w;}//*2有可能导致买太多了，减去一些
//        while(j<n){j+=m;k+=w;}//减去之后又可能太少了，加上一些
//        //其实就是大幅度地上调，然后做一些微调
//        if(k<ans||ans==0)ans=k;//判断是否是最小花费
//    }
//    printf("%d\n",ans);
//    return 0;//输出并返回
//}