#include <stdio.h>
#include <math.h>
//P5723 质数口袋问题
int main() {
    //筛选法判断质数
//    int sum = 0;
//    int L;
//    int cnt = 0;
//    scanf("%d", &L);
//    int A[2048] = {0};
//    for (int i = 0; i < 2048; ++i) {
//        A[i] = 1;
//    }
//    for (int i = 2; i < 2048 && sum < L; ++i) {
//        if (A[i]) {
//            sum += i;
//            if (sum <= L) {
//                printf("%d\n", i);
//                cnt++;
//            }
//        }
//        for (int j = i * i; j < 2048; j += i) {
//            A[j] = 0;
//        }
//    }
//    printf("%d", cnt);

//试除法，去偶数，开方优化，判断质数
    int sum = 0;
    int L;
    int cnt=0;
    scanf("%d",&L);
    if(L>=2){
        printf("2\n");
        cnt++;
    }
    for (int i = 3; i < 1200&&sum<L; i+=2) {
        int j;
        for ( j = 2; j <= sqrt(i) ; ++j) {
            if(i%j==0){
                break;
            }
        }
        if(j> sqrt(i)){
            sum+=i;
            if(sum<=L){
                printf("%d\n",i);
                cnt++;
            }
        }

    }
    printf("%d",cnt);

    return 0;
}
