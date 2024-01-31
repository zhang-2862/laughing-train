//#include <iostream>
//#include <string.h>
//
//
//int main() {
//    char str[10];
//    int len;
//    char str1[10];
//
//    scanf("%s",str);
//    len=strlen(str);
//    strcpy(str1,str);
////    printf("%d\n",len);
//
//    for (int i = 0; i < len; ++i) {
//        str1[i]=str[len-1-i];
//    }
//    str[5]='\0';
//    puts(str1);
//
////    printf(" %c%c%c%c%c", getchar(), getchar(), getchar(), getchar(), getchar());
//
//
//}
#include <bits/stdc++.h>
using namespace std;

char str[100];

int main() {
    scanf("%s",str + 1);
    int len = strlen(str + 1);
    for(int i=len;i>=1;i--) {
        printf("%c",str[i]);
    }

    return 0;
}