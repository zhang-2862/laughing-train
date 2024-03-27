#include <bits/stdc++.h>

using namespace std;
int main() {
    string str;
    while (cin>>str){
        for (int i = 3; i >=0; --i) {
            cout<<str[i];
        }
        cout<<endl;
    }

    return 0;
}
