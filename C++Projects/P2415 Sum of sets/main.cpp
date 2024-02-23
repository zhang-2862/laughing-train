#include <iostream>


int main() {
    long long sum=0;
    int tmp;
    int cnt=-1;
    while (std::cin>>tmp){
        sum+=tmp;
        cnt++;
    }
    std::cout<<(sum<<cnt);
    return 0;
}
