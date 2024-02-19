#include <iostream>
int arr[10001];

bool isPrime(int a){
    if(a==1||a==0){
        return false;
    }
    for (int i = 2; a >= i*i; ++i) {
        if(a%i==0){
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n; ++i) {
        if(isPrime(arr[i])){
            std::cout<<arr[i]<<" ";
        }
    }

    return 0;
}
