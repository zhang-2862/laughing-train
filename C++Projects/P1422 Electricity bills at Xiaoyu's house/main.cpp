#include <iostream>

int main() {
    int x;
    double price;
    scanf("%d",&x);
    if(x<=150){
        price=x*0.4463;
    } else if(x<=400){
        price=150*0.4463+(x-150)*0.4663;
    } else{
        price=150*0.4463+250*0.4663+(x-400)*0.5663;
    }
    printf("%.1lf",price);
    return 0;
}
