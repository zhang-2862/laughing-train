#include <iostream>
#include <stack>

using namespace std;
int main() {
    int A,B,D;
    cin>>A>>B>>D;
    stack<int> s;
    int sum=A+B;
    if(sum==0){
        cout<<sum<<endl;
    }
    while (sum!=0){
        s.push(sum%D);
        sum/=D;
    }
    while (!s.empty()){
        cout<<s.top();
        s.pop();
    }
    return 0;
}
