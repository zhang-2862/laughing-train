#include<iostream>
#include<list>
#include<vector>
using namespace std;

void printSVector(vector<string>& svec) {
	for (auto e:svec) {
		cout << e << endl;
	}
}
int main() {
	vector<string> svec;
	list<const char*> ccl{"ilovec++","abcd"};

	svec.assign(ccl.begin(), ccl.end());
	printSVector(svec);


	return 0;
}