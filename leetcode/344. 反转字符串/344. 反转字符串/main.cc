//Created on ...24/6/19
#include <iostream>
#include <vector>

using namespace std;
void reverseString(vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
        char temp = s[right];
        s[right] = s[left];
        s[left] = temp;
        left++;
        right--;
    }
}
int main() {   
    string s;
    cin >> s;
    vector<char> vc(s.begin(), s.end());
    reverseString(vc);
    
    for (auto e : vc) {
        cout << e;
    }

    return 0;
}