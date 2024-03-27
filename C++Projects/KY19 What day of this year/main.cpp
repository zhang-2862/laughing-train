#include <iostream>

using namespace std;
bool isleapYear(int year){
    if((year%4==0 && year%100!=0) || year%400==0){
        return true;
        } else{
        return false;
    }
}
int month_not_leap[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int month_leap[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int main() {
    int year;
    int month;
    int day;
    while (cin>>year>>month>>day){
        int days=0;
        if(isleapYear(year)){
            for (int i = 0; i < month-1; ++i) {
                days+=month_leap[i];
            }
        } else{
            for (int i = 0; i < month-1; ++i) {
                days+=month_not_leap[i];
            }
        }
        days+=day;
        cout<<days<<endl;
    }
    return 0;
}
