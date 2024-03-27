#include <iostream>

using namespace std;

void func(int n){
    int cnt=0;
    int i;
    for (i=1; i*i<= n; ++i) {
        if(n%i==0){
            cnt++;
        }
    }
    i--;
    if(i*i==n){
        cout<<cnt*2-1<<endl;
    } else{
        cout<<cnt*2<<endl;
    }
}


int main() {
    int num;
    int x;
    cin>>num;
    for (int i = 0; i < num; ++i) {
        cin>>x;
        func(x);
    }
    return 0;
}
