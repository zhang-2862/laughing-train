#include <iostream>

int arr[1024][1024];

void dfs(int x,int y,int length){
    if(length==2){
        arr[x][y]=1;
        return;
    }
    for (int i = x; i < x+length/2; ++i) {
        for (int j = y; j < y+length/2; ++j) {
            arr[i][j]=1;
        }
    }
    dfs(x,y+length/2,length/2);
    dfs(x+length/2,y,length/2);
    dfs(x+length/2,y+length/2,length/2);
}

int main(){
    int x;
    int n=1;
    std::cin>>x;
    for (int i = 0; i < x; ++i) {
        n<<=1;
    }
    dfs(0,0,n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout<<(arr[i][j]^1)<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}