#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int score=0;
};

//升序排列
void sort1(Student stu[], int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (stu[j].score > stu[j + 1].score) {
                Student temp;
                temp=stu[j + 1];
                stu[j+1]=stu[j];
                stu[j]=temp;
            }
        }
    }
}

//降序排列
void sort0(Student stu[], int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (stu[j].score < stu[j + 1].score) {
                Student temp;
                temp=stu[j + 1];
                stu[j+1]=stu[j];
                stu[j]=temp;
            }
        }
    }
}

int main() {
    int n;
    int method;
    while (cin >> n >> method) {
        Student stu[n];
        for (int i = 0; i < n; ++i) {
            cin >> stu[i].name >> stu[i].score;
        }
        if (method == 1) {
            sort1(stu, n);
        } else if (method == 0) {
            sort0(stu, n);
        }
        for (int i = 0; i < n; ++i) {
            cout << stu[i].name << " " << stu[i].score << endl;
        }
    }
}
// 64 位输出请用 printf("%lld")
