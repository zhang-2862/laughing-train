#include <iostream>
#include <string>
#include <vector>
#define MESSAGE "Happy new year!"

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

int main() {
	//string s = "aabaaf";
	//int next[10] = { 0 };
	//getNext(next, s);
	//for (auto e : next) {
	//	cout << e << endl;
	//}
	cout << MESSAGE << endl;
	return 0;
}