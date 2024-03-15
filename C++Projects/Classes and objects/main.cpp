#include <iostream>
#include <string>
using namespace std;
//运算符重载
class Person{
public:

    int m_A;
    int m_B;

    //成员函数重载‘+’运算符
//    Person operator+(Person &p1){
//        Person p;
//        p.m_A= this->m_A+p1.m_A;
//        p.m_B= this->m_B+p1.m_B;
//        return p;
//    }

};
//全局函数重载‘+’运算符

Person operator+(Person &p1,Person &p2){
    Person p;
    p.m_A=p1.m_A+p2.m_A;
    p.m_B=p1.m_B+p2.m_B;
    return p;
}

ostream & operator<<(ostream &cout,Person &p){
    cout<<"p.m_A= "<<p.m_A<<" p.m_B= "<<p.m_B<<endl;
    return cout;
}



class  MyInteger{
    friend ostream & operator<<(ostream &cout,MyInteger myInteger);
public:
    MyInteger& operator++(){
        m_Num++;
        return *this;
    }

    MyInteger operator++(int){
        MyInteger temp=*this;
        m_Num++;
        return temp;
    }
private:
    int m_Num=0;
};

ostream & operator<<(ostream &cout,MyInteger myInteger){
    cout<<myInteger.m_Num;
    return cout;
}

void test01(){
    Person p1;
    p1.m_A=10;
    p1.m_B=10;

    Person p2;
    p2.m_A=10;
    p2.m_B=10;

    Person p3=p1+p2;
    cout<<p3<<endl;
//    cout<<"p3.m_A= "<<p3.m_A<<endl<<"p3.m_B= "<<p3.m_B<<endl;
}

void test02(){
    MyInteger myInteger;
    cout<<myInteger++<<endl;
    cout<<++myInteger<<endl;
}

int main() {
//    test01();

    test02();

    return 0;
}
