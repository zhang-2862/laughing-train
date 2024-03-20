#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "������˵��..." << endl;
    }

};

class Cat: public Animal{
public:
    void speak(){
        cout<<"Сè��˵��..."<<endl;
    }
};

class Dog: public Animal{
public:
    void speak(){
        cout<<"С����˵��..."<<endl;
    }
};

void doSpeak(Animal &animal){
    animal.speak();
}

void test01(){
    Cat cat;
    Dog dog;
    doSpeak(cat);
    doSpeak(dog);
}
int main() {
    test01();


    return 0;
}

