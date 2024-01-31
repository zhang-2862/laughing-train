#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int step(int n)
{
    if(n==1|n==2)
    {
        return n;
    }
    return step(n-1)+ step(n-2);
}

int f1(unsigned n ){
    int sum=1,power=1;
    for (unsigned i = 0; i <= n-1; ++i) {
        power*=2;
        sum+=power;
    }
    return sum;
}


int main() {
//    int n;
//
//    scanf("%d",&n);
//    printf("step(%d)=%d\n",n,step(n));

    printf("%d", f1(3));

    return 0;
}


