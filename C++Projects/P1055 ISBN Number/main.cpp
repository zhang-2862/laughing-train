#include <iostream>

int main() {
    char a[10];
    char x;
    int r=0;
    int m;
    for (int i = 0,j=0; i < 13; ++i) {
        x=getchar();
        if(x>='0' && x<='9' || x=='X'){
            a[j]=x;
            if(i==12)break;
            r+=(j+1)*(a[j]-'0');
            ++j;
        }
    }
    m=r%11;
    if(m>=10){
        x='X';
    } else{
        x='0'+m;
    }
    if(x==a[9]){
        printf("Right");
    } else{
        printf("%c-",a[0]);
        for (int i = 1; i < 4; ++i) {
            printf("%c",a[i]);
        }
        printf("-");
        for (int i = 4; i < 9 ; ++i) {
            printf("%c",a[i]);
        }
        printf("-%c",x);
    }
    return 0;
}
