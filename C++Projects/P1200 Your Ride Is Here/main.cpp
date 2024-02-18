#include <iostream>
#include <cstring>

using namespace std;
char str1[7];
char str2[7];
int mul1=1;
int mul2=1;


int main() {
    cin>>str1;
    cin>>str2;

    for (int i = 0; i < strlen(str1); ++i) {
        mul1*=int(str1[i]-'A'+1);
    }
    for (int i = 0; i < strlen(str2); ++i) {
        mul2*=int(str2[i]-'A'+1);
    }
    if(mul1%47==mul2%47){
        cout<<"GO";
    } else{
        cout<<"STAY";
    }
    return 0;
}
