#include <stdio.h>

int main() {
    double score[10];//定义一个双精度浮点型数组
    double average=0;//最终平均分
    int n;//评委人数
    int sum;//评分总和
    int max;
    int min;

    scanf("%d",&n);//读取评委人数
    //利用for循环读取分数的同时，用if语句锁定最小值，最大值的数组序号。
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &score[i]);
        if (i==0) {//将第一个读入的数设置为最大值，最小值的初始值
            min = i;
            max = i;
        } else if (score[i] < score[min]) {//如果数组下标为i的数小于最小值则更新min
            min = i;
        } else if (score[i] > score[max]) {//如果数组下标为i的数大于最小值则更新max
            max = i;
        }
    }

//    for (int i = 0; i < n; ++i) {
//        printf("%.2lf\n",score[i]);
//    }
    //利用for循环求出评分总和sum
    for (int i = 0; i < n; ++i) {
        sum+=score[i];
    }
    //最终平均分等于总分-最小值-最大值，之后除以评委人数-2
    average=(sum-score[min]-score[max])/(n-2);
    printf("%.2lf\n",average);

    return 0;
}

