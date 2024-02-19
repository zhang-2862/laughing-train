#include <iostream>

using namespace std;

char graph[100][51];

int main() {
    int max=0;
    int cnt;
    //初始化
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 51; ++j) {
            graph[i][j]=' ';
        }
    }
    string s;
    int val[26]={0};
    for (int i = 0; i < 4; ++i) {
        getline(cin,s);
        for (int j = 0; j < s.length(); ++j) {
            if(s[j]<='Z' && s[j]>='A'){
                val[s[j]-'A']++;
            }
        }
    }
    //找最长列
    for (int i = 0; i < 26; ++i) {
        if(val[i]>max){
            max=val[i];
        }
    }

    //绘图
    for (int j = 0; j < 51; j+=2) {
        cnt=0;
        for (int  i= 98 ;  cnt<val[j/2]&&i>=0; i--) {
            graph[i][j]='*';
            cnt++;
        }
    }
    for (int j = 0; j < 51; ++j) {
        if(j%2==0){
            graph[99][j]='A'+j/2;
        }
    }
    //输出
    for (int i = 99-max; i < 100; ++i) {
        for (int j = 0; j < 51; ++j) {
            cout<<graph[i][j];
        }
        if(i<99){
            cout<<endl;
        }
    }

    return 0;
}


