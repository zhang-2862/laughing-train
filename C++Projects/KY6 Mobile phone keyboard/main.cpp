#include <iostream>

using namespace std;
//ABC 	DEF
//GHI 	JKL 	MNO
//PQRS 	TUV 	WXYZ

int key[26]={1,2,3,
            1,2,3,
            1,2,3,
            1,2,3,
            1,2,3,
            1,2,3,4,
            1,2,3,
            1,2,3,4};

int main() {
    string str;
    while(cin>>str){
        int cnt=0;
        for (int i = 0; i < str.size(); ++i) {
            cnt+=key[str[i]-'a'];
            if(i>0 && (key[str[i]-'a']-key[str[i-1]-'a'])==(str[i]-str[i-1])){
                cnt+=2;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
