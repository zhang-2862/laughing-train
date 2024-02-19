#include <iostream>

bool isLeapYear(int year){
    if((year%100!=0 && year%4==0) || year%400==0){
        return true;
    }
    return false;
}

int main() {
    int year1,year2;
    int cnt=0;
    std::cin>>year1>>year2;
    for (int i = year1; i <=year2 ; ++i) {
        if(isLeapYear(i)){
            cnt++;
        }
    }
    std::cout<<cnt<<std::endl;
    for (int i = year1; i <=year2 ; ++i) {
        if(isLeapYear(i)){
            std::cout<<i<<" ";
        }
    }
    return 0;
}
