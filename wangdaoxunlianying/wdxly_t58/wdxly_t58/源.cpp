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

	cout << "�ѳɹ�¼��ĵ����У� " << endl;
	for (auto e : words) {
		cout << e << endl;
	}
}