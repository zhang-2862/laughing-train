#include <iostream>
#define NUM 1000000000
using namespace std;
int dp[1000000];


void integer_split(int n){
    dp[1]=1;
    for (int i = 2; i <= n; ++i) {
        if(i%2==0){
            dp[i]=(dp[i-1]+dp[i/2])%NUM;
        } else{
            dp[i]=dp[i-1];
        }
    }
}


int main() {
    int n;
    cin>>n;
    integer_split(n);
    int res=dp[n];
    cout<<res<<endl;
    return 0;
}
