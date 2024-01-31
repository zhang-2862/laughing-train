#include <iostream>
using namespace std;
int main() {
    double m,h,bmi;
    scanf("%lf%lf",&m,&h);
    bmi=m/(h*h);
    if(bmi<18.5){
        printf("Underweight");
    } else if(bmi<24){
        printf("Normal");
    } else{
            std::cout<<bmi<<std::endl<<"Overweight";
    }
    return 0;

}
