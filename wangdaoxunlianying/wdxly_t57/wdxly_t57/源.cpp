#include<iostream>
#include<map>
#include <vector>
#include <string>

using namespace std;

int main() {
	map<string, vector<string>> family;
	string surname;
	string name;
	bool if_continue_o = true;
	bool if_continue_i=true;
	while (if_continue_o)
	{
		cout << "����������: " << endl;
		cin >> surname;
		cout << "����������: " << endl;
		while (if_continue_i) {
			cin >> name;
			family[surname].push_back(name);
			cout << endl;
			cout << "�Ƿ����¼����������������1������������0" << endl;
			cin >> if_continue_i;
		}
		cout << "�Ƿ����������������1������������0" << endl;
		cin >> if_continue_o;
	}
	cout << "����Ϊ�Ѵ�����Ϣ�� " << endl;
	for (auto& f : family) {
		cout << "���ϣ� " << f.first  << endl;
		for (auto v : f.second) {
			cout << "���� " <<v<< endl;
		}
	}


	return 0;
}