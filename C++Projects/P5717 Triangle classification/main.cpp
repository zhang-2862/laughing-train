#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    int s1,s2;
    scanf("%d%d%d",&a,&b,&c);
    if(a>c)swap(a,c);
    if(b>c)swap(b,c);
    if(a+b>c){
        if((a*a+b*b)==c*c){
            printf("Right triangle\n");
        }else if((a*a+b*b)>c*c){
            printf("Acute triangle\n");
        } else{
            printf("Obtuse triangle\n");
        }
        if(a==c && a==b && b==c){
            printf("Isosceles triangle\n");
            printf("Equilateral triangle\n");
        } else if(a==b){
            printf("Isosceles triangle\n");
        }
    } else{
        printf("Not triangle\n");
    }

    return 0;
}
