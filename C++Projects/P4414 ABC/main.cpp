#include <iostream>
using namespace std;
int main() {
    int a,b,c;
    char x;
    scanf("%d%d%d",&a,&b,&c);
    if(a>b){
        swap(a,b);
    }
    if(b>c){
        swap(b,c);
    }
    if(a>b){
        swap(a,b);
    }
    for (int i = 0; i < 3; ++i) {
        cin>>x;
        if(x=='A')
        {
            printf("%d ",a);
        }
        if(x=='B')
        {
            printf("%d ",b);
        }
        if(x=='C')
        {
            printf("%d ",c);
        }
    }

    return 0;
}

