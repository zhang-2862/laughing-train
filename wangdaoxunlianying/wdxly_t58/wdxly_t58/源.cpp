#include <iostream>
#include<vector>

using namespace std;

int main() {
	vector<string> words;
	string word;
	while (cin >> word) {
		if (find(words.cbegin(), words.cend(), word)==words.end()) {
			words.push_back(word);
		}
	}

	cout << "已成功录入的单词有： " << endl;
	for (auto e : words) {
		cout << e << endl;
	}
}