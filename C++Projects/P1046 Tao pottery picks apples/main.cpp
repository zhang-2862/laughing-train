#include <iostream>

int main() {
    int high[10];
    for (int i = 0; i < 10; ++i) {
        scanf("%d",&high[i]);
    }
    int tHigh;
    int sum=0;
    scanf("%d",&tHigh);
    for (int i = 0; i < 10; ++i) {
        if(tHigh+30>=high[i]){
            ++sum;
        }
    }
    printf("%d",sum);

    return 0;
}
