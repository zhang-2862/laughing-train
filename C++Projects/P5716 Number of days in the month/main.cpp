#include <iostream>

int main() {
    int mon,year;
    scanf("%d%d",&year,&mon);
    switch (mon) {
        case 2:
            printf("%d",28+(year%4==0 && year%100!=0 ||year%400==0));
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("31");
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf("30");
            break;
        default:
            break;
    }
    return 0;
}
