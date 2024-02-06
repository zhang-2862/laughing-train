#include <iostream>


using namespace std;

int main() {
    int n;
    int cnt=0;
    cin>>n;
    char str[100]={0};
    cin>>str;
    for (int i = 0; i < n; ++i) {
        if(str[i]=='V' && str[i+1]=='K'){
            cnt++;
            str[i]='v';
            str[i+1]='k';
        }
    }

    for (int i = 0; i < n; ++i) {
        if( (str[i]=='V' && str[i+1]=='V')||(str[i]=='K' && str[i+1]=='K')){
            cnt++;
            cout<<cnt<<endl;
            return 0;
        }
    }

    cout<<cnt<<endl;
    return 0;
}
