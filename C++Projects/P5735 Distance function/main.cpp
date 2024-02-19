#include <iostream>
#include <math.h>


double cal_dis(double x1, double y1, double x2, double y2){
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}


int main() {
    double arr[3][2];
    double c=0;
    for (int i = 0; i < 3; ++i) {
        scanf("%lf%lf",&arr[i][0],&arr[i][1]);
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = i+1; j < 3; ++j){
            c += cal_dis(arr[i][0], arr[i][1], arr[j][0], arr[j][1]);
        }
    }

    printf("%.2lf",c);
    return 0;
}
