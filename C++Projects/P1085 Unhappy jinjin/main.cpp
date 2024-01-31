#include <iostream>

using namespace std;
int main() {
    int a;
    int b;
    int s;
    int max=0;
    int day=0;
    for (int i = 0; i < 7; ++i) {
        scanf("%d%d",&a,&b);
        s=a+b;
        if(s>max && s>8){
            max=s;
            day=i+1;
        }
    }
    printf("%d",day);
    return 0;
}
