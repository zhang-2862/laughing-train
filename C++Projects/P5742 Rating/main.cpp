#include <iostream>

typedef struct Student{
    int ID=0;
    int GPA=0;
    int QES=0;//素质拓展成绩
    int CScore=0;//综合成绩
    int sum(){
        return GPA+QES;
    }
}Student;

Student student[1024];

void judgeExcellent(Student x){
    if(x.sum()>140 && (x.GPA*7+x.QES*3)>=800){
        printf("Excellent\n");
    } else{
        printf("Not excellent\n");
    }
}

int main() {
    int n;
    std::cin>>n;

    for (int i = 0; i < n; ++i) {
        std::cin>>student[i].ID;
        std::cin>>student[i].GPA;
        std::cin>>student[i].QES;
        student[i].CScore=student[i].GPA*0.7+student[i].QES*0.3;
        judgeExcellent(student[i]);
    }
    return 0;
}
