#include <iostream>

int main() {
    int m,t,s;
    scanf("%d%d%d",&m,&t,&s);
    int res;
    if(t==0){
        printf("%d",0);
    }else{
        if(s%t==0){
            res=m-s/t;
        } else{
            res=m-s/t-1;
        }
        if(res>0){
            printf("%d",res);
        } else{
            printf("%d",0);
        }
    }
    return 0;
}
