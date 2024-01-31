#include <iostream>
using namespace std;

int GCD(int a,int b){
    if(b==0){
        return a;
    }
    return GCD(b,a%b);
}

int main() {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a<b){
        swap(a,b);
    }
    if(b<c){
        swap(b,c);
    }
    if(a<b){
        swap(a,b);
    }
    printf("%d/%d",c/ GCD(a,c),a/ GCD(a,c));
    return 0;
}
