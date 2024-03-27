#include <iostream>
#include <algorithm>

using namespace std;
struct Student{
    int num=0;
    int score=0;
};

Student student[100];
bool cmp(Student a,Student b){
    if(a.score<b.score){
        return true;
    } else if(a.score==b.score){
        if(a.num<b.num){
            return true;
        }
    }
    return false;
}
int main() {
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>student[i].num>>student[i].score;
    }
    sort(student,student+n,cmp);
    for (int i = 0; i < n; ++i) {
        cout<<student[i].num<<" "<<student[i].score<<endl;
    }
    return 0;
}
