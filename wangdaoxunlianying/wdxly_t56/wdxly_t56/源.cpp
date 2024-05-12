#include <iostream>
#include<string>

using namespace std;

string func(string &s,const string &strfront,const string &strback) {
	s.insert(s.begin(),strfront.begin(),strfront.end());
	s.append(strback);
	return s;
}

int main() {
	string name("уе╦у");
	string sfront("Mr.");
	string sback("III");
	string s=func(name, sfront, sback);
	cout << s << endl;
	return 0;
}