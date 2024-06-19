//Created on ..24/6/19
#include <iostream>
#include <vector>

using namespace std;

void getNext(vector<int>& next, string s) {
    int j = -1;
    next[0] = j;
    for (int i = 1; i < s.size(); i++)
    {
        while (j >= 0 && s[i] != s[j + 1]) {
            j = next[j];
        }
        if (s[i] == s[j+1]) {
            j++;
        }
        next[i] = j;
    }
}

bool repeatedSubstringPattern(string s) {
    if (s.size() == 0) {
        return false;
    }
    vector<int> next(s.size());
    getNext(next, s);
    int length = s.size();
    if (next[length-1]!=-1 && length % (length-next[length-1]-1) ==0) {
      return true;
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    if (repeatedSubstringPattern(s)) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }

    return 0;
}