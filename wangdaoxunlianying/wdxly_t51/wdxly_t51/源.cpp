#include<iostream>
#include<vector>
#include<list>
using namespace std;

/*
如何从一个 list<int>初始化一个 vector<double> ? 从一个 vector<int>又
该如何创建？编写代码验证你的答案
*/

void printDVector(vector<double> &dv){
	for (auto i : dv) {
		cout << i << " ";
	}
	cout << endl;
}



int main() {
	list<int>il{1, 2, 3, 4, 5, 6};
	vector<int>iv{ 10,20,30,40,50,60 };
	vector<double>dv1(il.begin(), il.end());
	vector<double>dv2(iv.begin(), iv.end());
	cout << "dv1: " << endl;
	printDVector(dv1);
	cout << "dv2: " << endl;
	printDVector(dv2);
	return 0;
}