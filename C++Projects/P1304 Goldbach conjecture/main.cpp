#include <iostream>

bool isPrime(int x){
    if(x==0 || x==1){
        return false;
    }
    for (int i = 2; x >=i*i ; i++) {
        if(x%i==0){
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    std::cin>>n;
    for (int i = 4; i <= n; i+=2) {
        for (int j = 2; j < i; ++j) {
            if(isPrime(j) && isPrime(i-j)){
                printf("%d=%d+%d\n",i,j,i-j);
                break;
            }
        }
    }

    return 0;
}
