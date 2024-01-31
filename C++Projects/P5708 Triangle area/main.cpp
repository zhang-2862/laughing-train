#include <iostream>
#include <math.h>
int main() {
    float a;
    float b;
    float c;
    float p;
    float s;
    scanf("%f%f%f",&a,&b,&c);
    p=(a+b+c)/2;
    s= sqrt(p*(p-a)*(p-b)*(p-c));
    printf("%.1f",s);
    return 0;
}
