#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getNext(int* next, const string& s) {
	int j = -1;
	next[0] = j;
	for (int i = 1; i < s.size(); i++) {
		while (j >= 0 && s[i] != s[j + 1]) {
			j = next[j];
		}
		if (s[i] == s[j + 1]) {
			j++;
		}
		next[i] = j;
	}
}

void test(){
	string s = "aabaaf";
	int next[10] = { 0 };
	getNext(next, s);
	for (auto e : next) {
		cout << e << endl;
	}
}

int* foo() {
	int arr[5] = { 0,1,2,3,4 };
	return &arr[3];
}

int bar() {
	printf("bar has called.\n");
	return 0;
}

int main() {
	int* p = foo();
	bar();
	printf("%d", *p);
	return 0;
}