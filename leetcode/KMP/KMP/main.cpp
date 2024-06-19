#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getNext(vector<int>& next, const string& s) {
	int j = -1;
	next[0] = j;
	for (int i = 1; i < s.size()-1; i++)
	{
		while (j >= 0 && s[i] != s[j + 1]) {
			j = next[j];
		}
		if (s[i] == s[j + 1]) {
			j++;
		}
		next[i] = j;
	}
}

int strStr(string haystack,string needle) {
	if (needle.size() == 0) {
		return false;
	}
	vector<int> next(needle.size());
	getNext(next,needle);
	int j = -1;
	for (int i = 0; i < haystack.size(); i++)
	{
		while (j >= 0 && haystack[i] != needle[j + 1]) {
			j = next[j];
		}
		if (haystack[i] == needle[j + 1]) {
			j++;
		}
		if (j == needle.size() - 1) {
			return i - needle.size() + 1;
		}
	}
	return -1;
}

int main() {
	string str1;
	cout << "please input query string" << endl;
	cin >> str1;	
	string needle;
	cout << "please input needle string" << endl;
	cin >> needle;

	cout << "needle pos is " << strStr(str1, needle);
	

	return 0;
}