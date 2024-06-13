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

int main() {
	//string s = "aabaaf";
	//int next[10] = { 0 };
	//getNext(next, s);
	//for (auto e : next) {
	//	cout << e << endl;
	//}
	int n = 0xCAFE;
	//将末四位剥离出来
	n &= 15;

	//统计末四位中一的个数
	int cnt = 0;
	while (n) {
		n=n& (n - 1);
		cnt++;

	}
	printf("cnt = %d\n", cnt);


	int v = 0xCAFE;
	v = ((v >> 1) & 0x55555555) | ((v & 0x55555555) << 1);
	v = ((v >> 1) & 0x55555555) | ((v & 0x55555555) << 1);
	printf("%X\n", v);
	return 0;
}