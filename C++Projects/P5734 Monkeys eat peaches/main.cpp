#include <iostream>

int main() {
    int n;
    int sum=1;
    std::cin>>n;
    for (int i = 0; i < n-1; ++i) {
        sum=(sum+1)*2;
    }
    std::cout<<sum<<std::endl;
    return 0;
}
