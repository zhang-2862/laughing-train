#include<iostream>
#include <deque>
#include<string>

using namespace std;

int main() {
	deque<string> sdeq;
	string str;
	while (getline(cin,str)) {
		sdeq.push_back(str);
	}
	for (auto iter = sdeq.cbegin(); iter != sdeq.cend(); iter++) {
		cout << *iter << endl;
	}


	return 0;
}