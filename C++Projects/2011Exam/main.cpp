#include <stdio.h>

//int findMedianSortedArrays( int a[], int b[],int len ) {
//    int n = len;
//    int pa = 0, pb = 0, ma, mb;
//    while (n > 1) {
//        ma = pa + (n + 1) / 2 - 1;
//        mb = pb + (n + 1) / 2 - 1;
//        if (a[ma] == b[mb]) return a[ma];
//        if (a[ma] < b[mb]) {
//            pa += n / 2;
//        } else {
//            pb += n / 2;
//        }
//        n = (n + 1) / 2;
//    }
//    return a[pa]<= b[pb]?a[pa]:b[pa];
//}

int find_mid(int a[],int b[],int len){
    int s1=0,s2=0,d1=len-1,d2=len-1,m1,m2;
    while (s1!=d1||s2!=d2){
        m1=(s1+d1)/2;
        m2=(s2+d2)/2;
        if(a[m1]==b[m2]){
            return a[m1];
        }else if(a[m1]<b[m2]){
            //分别考虑奇数个和偶数个
            if((s1+d1)%2==0){//奇数个
                s1=m1;
                d2=m2;
            } else{
                s1=m1+1;
                d2=m2;
            }

        } else{
            if((s1+d1)%2==0){
                d1=m1;
                s2=m2;
            } else{
                d1=m1;
                s2=m2+1;
            }
        }
    }
    return a[s1]<b[s2]?a[s1]:b[s2];
}


int main() {
    int S1[5]={11,13,15,17,19};
    int S2[5]={2,4,6,8,20};
//    int res=findMedianSortedArrays(S1,S2,5);
    int res=find_mid(S1,S2,5);
    printf("%d",res);
    return 0;
}
