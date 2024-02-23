#include <iostream>

typedef struct Student{
    char name[15]="weizhi";
    int age=0;
    int score=0;
};

void cultivate(Student &student){
    student.age+=1;
    if(student.score*6/5<=600){
        student.score=student.score*6/5;
    } else{
        student.score=600;
    }
}

int main() {
    Student student;
    int n;
    std::cin>>n;


    for (int i = 0; i < n; ++i) {
        std::cin>>student.name;
        std::cin>>student.age;
        std::cin>>student.score;
        cultivate(student);
        std::cout<<student.name<<" "<<student.age<<" "<<student.score<<std::endl;
    }


    return 0;
}
