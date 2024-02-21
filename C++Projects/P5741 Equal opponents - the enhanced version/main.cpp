#include <iostream>

typedef struct Student{
    char Name[9]="weizhi";
    int Chinese=0;
    int Math=0;
    int English=0;
    int SumScore=0;
}Student;

Student students[1000];

bool isEqual(Student student1,Student student2){
    if(student1.Chinese-student2.Chinese<=5 && student1.Chinese-student2.Chinese>=-5){
        if(student1.Math-student2.Math<=5 && student1.Math-student2.Math>=-5){
            if(student1.English-student2.English<=5 && student1.English-student2.English>=-5){
                if(student1.SumScore-student2.SumScore<=10 && student1.SumScore-student2.SumScore>=-10){
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {

    int n;
    std::cin>>n;

    for (int i = 0; i < n; ++i) {
        std::cin>>students[i].Name;
        std::cin>>students[i].Chinese;
        std::cin>>students[i].Math;
        std::cin>>students[i].English;
        students[i].SumScore=students[i].Chinese+students[i].Math+students[i].English;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(isEqual(students[i],students[j])){
                std::cout<<students[i].Name<<" "<<students[j].Name<<std::endl;
            }
        }
    }

    return 0;
}
