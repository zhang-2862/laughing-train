#include <iostream>

int main() {
#define PI 3.14
    int h;
    int r;
    scanf("%d%d",&h,&r);
    double water;
    water=h*PI*r*r;
    int res;
    res=20000/water+1;
    printf("%d",res);

    return 0;
}
