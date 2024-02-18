#include <iostream>
#include <algorithm>
using namespace std;
//one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty
string map[27]={"0","one","two","three","four",
                "five","six","seven","eight","nine","ten",
                "eleven","twelve","thirteen","fourteen","fifteen",
                "sixteen","seventeen","eighteen","nineteen","twenty"
        ,"a","both","another","first","second","third"};

int value[27]={0,1,4,9,16,25,36,
               49,64,81,0,21,44,
               69,96,25,56,89,24,
               61,0,1,4,1,1,4,9};

int k;
int num[6];

int main()
{
    for (int i = 0; i < 6; ++i) {
        string x;
        cin>>x;
        for (int j = 1; j < 27; ++j) {
            if(x==map[j]){
                num[k++]=value[j];
                break;
            }
        }
    }
    if(k==0){
        cout<<"0";
        return 0;
    }
    sort(num,num+k);
    for (int i = 0; i < k; ++i) {
        if(num[i]<10 && i!=0){
            cout<<0;
        }
        cout<<num[i];
    }
    return 0;
}