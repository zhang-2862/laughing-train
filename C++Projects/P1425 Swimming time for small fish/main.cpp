#include <iostream>

int main() {
    int a,b,c,d,e,f;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(d-b>=0){
        e=c-a;
    } else{
        e=c-a-1;
    }
    f=(60+d-b)%60;
    printf("%d %d",e,f);
    return 0;
}
