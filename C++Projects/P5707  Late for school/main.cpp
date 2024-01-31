#include <iostream>

int main() {
    int s;
    int v;
    scanf("%d%d",&s,&v);
    int h0;
    int h;
    int m;
    h0=7-(s/v+10)/60;
    h=(24+h0)%24;

    if (s%v==0){
        m=60-(s/v+10)%60;
    } else{
        m=59-(s/v+10)%60;
    }
    printf("%02d:%02d",h,m);


    return 0;
}
