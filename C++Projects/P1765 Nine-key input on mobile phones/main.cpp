#include <iostream>
using namespace std;

int cnt;
char alp[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,
              1,2,3,4,1,2,3,1,2,3,4};

int main() {
    string str;
    getline(cin,str);
    for (int i = 0; i < str.length(); ++i) {
        if(str[i]>='a' && str[i]<='z'){
            cnt+=alp[str[i]-'a'];
        } else if (str[i]==' '){
            ++cnt;
        }
    }
    printf("%d",cnt);
    return 0;
}
