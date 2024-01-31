#include <stdio.h>

int main() {
    int a[5];
    for (int i = 0; i < 5; ++i) {
        scanf("%d",&a[i]);
    }
    int res=0;
    for (int i = 0; i < 5; ++i) {
        res ^= a[i];
    }
    printf("%d\n",res);
    return 0;
}
