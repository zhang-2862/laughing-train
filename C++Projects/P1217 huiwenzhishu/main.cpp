#include <iostream>
//回文质数
bool isPrime(int x) {
    int i;
    for (i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

bool isEven(int x) {
    if ((10 <= x && x<=100 && x != 11) || (1000 <= x && x <= 10000) || (100000 <= x && x <= 1000000) )
         {
        return false;
    } else {
        return true;
    }
}
//12
bool isPalindrome(int x) {
    int temp = x;
    int res = 0;
    while (x != 0) {
        res = res * 10 + x % 10;
        x /= 10;
    }

    if (temp == res) {
        return true;
    } else {
        return false;
    }

}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    if(b>9999999){
        b=9999999;
    }
    if(a%2==0){
        a++;
    }
    for (int i = a; i <= b; i+=2) {
        if (!isEven(i))continue;
        if (!isPalindrome(i))continue;
        if (!isPrime(i))continue;

        printf("%d\n", i);

    }

    return 0;
}
