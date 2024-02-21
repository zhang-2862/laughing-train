#include <iostream>
#include <cstring>

typedef struct Student{
    char Name[10];
    int Chinese;
    int Math;
    int English;
    int SumScore;
}Student;

Student students[1001];

int main() {
    int n;


    int num=0;//记录学生序号
    int max=0;

    std::cin>>n;

    for (int i = 0; i < n; ++i) {
        std::cin>>students[i].Name;
        std::cin>>students[i].Chinese;
        std::cin>>students[i].Math;
        std::cin>>students[i].English;
        students[i].SumScore=students[i].Chinese+students[i].Math+students[i].English;

    }
    for (int i = 0; i < n; ++i) {
        if(students[i].SumScore>max){
            max=students[i].SumScore;
            num=i;
        }
    }
    std::cout<<students[num].Name<<" ";
    std::cout<<students[num].Chinese<<" ";
    std::cout<<students[num].Math<<" ";
    std::cout<<students[num].English<<std::endl;
    return 0;
}
