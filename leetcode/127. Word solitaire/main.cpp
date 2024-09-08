#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::set;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.count(endWord) == 0) {
            return 0;
        }
        std::unordered_set<string> s1{beginWord};
        std::unordered_set<string> s2{endWord};
        int step = 1;

        while (!s1.empty() && !s2.empty()) {
            ++step;
            // 交换搜索的容器，提升搜索效率
            if (s1.size() > s2.size()) {
                std::swap(s1, s2);
            }

            std::unordered_set<string> s;

            for (auto& word : s1) {
                wordSet.erase(word);
            }
            for (auto& word : s2) {
                wordSet.erase(word);
            }

            for (auto word : s1) {
                for (int i = 0; i < word.size(); ++i) {
                    char ch = word[i];
                    for (int j = 0; j < 26; j++) {
                        word[i] = 'a' + j;
                        if (s2.count(word) == 1) {
                            return step;
                        }
                        if (wordSet.count(word) == 0) {
                            continue;
                        }
                        // 在单词集里存在，则插入到s中
                        s.insert(word);
                    }
                    word[i] = ch;
                }
            }
            s1 = s;
        }
        return 0;
    }
};

int main(int argc, char* argv[]) {
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    int ret = Solution().ladderLength("hit","cog",wordList);
    cout << ret << endl;

    return 0;
}
