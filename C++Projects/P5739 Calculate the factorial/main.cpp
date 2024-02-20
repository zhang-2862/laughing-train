#include <iostream>

int factorial(int x){
    if(x==1){
        return 1;
    }
    return x*factorial(x-1);
}

int main() {
    int n;
    std::cin>>n;

    std::cout<<factorial(n);
    return 0;
}
