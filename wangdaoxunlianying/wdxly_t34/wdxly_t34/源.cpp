#include <iostream>
using namespace std;

class Student {
public:
	friend void level(Student &stu);
	void setName(string str) {
		name = str;
	}
	void setScore(int sco) {
		score = sco;
	}
private:
	string name;
	int score;
};

void level(Student &stu) {
	if (stu.score >= 90) {
		cout <<stu.name<<"�ĳɼ�Ϊ��" << "��" << endl;
	}
	else if (stu.score >= 80) {
		cout << stu.name << "�ĳɼ�Ϊ��" << "��" << endl;
	}
	else if (stu.score >= 70) {
		cout << stu.name << "�ĳɼ�Ϊ��" << "��" << endl;
	}
	else if (stu.score >= 60) {
		cout << stu.name << "�ĳɼ�Ϊ��" << "����" << endl;
	}
	else {
		cout << stu.name << "�ĳɼ�Ϊ��" << "������" << endl;
	}
}


int main() {
	Student student;
	student.setName("����");
	student.setScore(78);
	level(student);

	system("pause");
	return 0;
}
