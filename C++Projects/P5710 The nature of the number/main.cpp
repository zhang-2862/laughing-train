#include <iostream>

int main() {
    int x;
    scanf("%d",&x);
    int k;
    int a=0,b=0,c=0,d=0;
    k+=(x%2==0);
    k+=(x>4 && x<=12);
    if(k==2){
        a=1;
    }
    if(k>=1){
        b=1;
    }
    if(k==1){
        c=1;
    }
    if(k==0){
        d=1;
    }
    printf("%d %d %d %d",a,b,c,d);
    return 0;
}
