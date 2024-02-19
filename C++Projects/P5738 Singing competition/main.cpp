#include <iostream>
#include <algorithm>

using namespace std;

double Score[20];
double AveScore[100];

double findAveScore(double a[],int m){
    sort(a,a+m);
    double Ave=0;
    for (int i = 1; i < m-1; ++i) {
        Ave+=a[i];
    }
    return Ave/(m-2);
}


int main() {
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>Score[j];
        }
        AveScore[i]=findAveScore(Score,m);
    }
    sort(AveScore,AveScore+n);
    printf("%.2lf",AveScore[n-1]);
    return 0;
}
