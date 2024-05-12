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
		cout << "请输入姓氏: " << endl;
		cin >> surname;
		cout << "请输入名字: " << endl;
		while (if_continue_i) {
			cin >> name;
			family[surname].push_back(name);
			cout << endl;
			cout << "是否继续录入名，继续请输入1，否则请输入0" << endl;
			cin >> if_continue_i;
		}
		cout << "是否继续，继续请输入1，否则请输入0" << endl;
		cin >> if_continue_o;
	}
	cout << "以下为已存入信息： " << endl;
	for (auto& f : family) {
		cout << "姓氏： " << f.first  << endl;
		for (auto v : f.second) {
			cout << "名： " <<v<< endl;
		}
	}


	return 0;
}