#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int boy=0;
    int girl=0;
    char str[255]={0};
    cin>>str;
    for (int i = 0; i < strlen(str); ++i) {
        if(str[i]=='b' || str[i+1]=='o' || str[i+2]=='y'){
            boy++;
        }
        if(str[i]=='g' || str[i+1]=='i' || str[i+2]=='r' || str[i+3]=='l'){
            girl++;
        }
    }

    cout<<boy<<endl;
    cout<<girl<<endl;

    return 0;
}
