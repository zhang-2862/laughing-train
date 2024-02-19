#include <iostream>

char x1,x2;
int a[3];

int main() {


    while (scanf("%c:=%c;",&x1,&x2)==2){
        a[x1-'a']=x2>='0' && x2<='9' ? x2-'0' : a[x2-'a'];
    }
    printf("%d %d %d",a[0],a[1],a[2]);

    return 0;
}
