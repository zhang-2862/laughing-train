#include <iostream>

//找数组中未出现的最小正整数
int findSmall(int A[],int length){
    int tag=1;
    for (int i = 0; i < length; ++i) {
        if(A[i]==tag){
            tag++;
        }
    }
    return tag;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int A[4]={-5,3,2,3};
    int B[6]={1,1,2,9,9,6};
    int res=findSmall(B,6);
    printf("%d",res);
    return 0;
}
