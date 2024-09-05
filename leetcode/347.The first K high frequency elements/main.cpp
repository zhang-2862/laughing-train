#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    struct CompareByValue {
        bool operator()(pair<int,int> lhs, pair<int,int> rhs) {
            return lhs.second > rhs.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res(k);

        for (const auto &item: nums) {
            ++map_[item];
        }

        for (const auto &item: map_) {
            // 仅需维护K个元素
            p_que_.emplace(item);
            if (p_que_.size() > k) {
                p_que_.pop();
            }
        }

        for (int i = 0; i < k; ++i) {
            res[i] = p_que_.top().first;
            p_que_.pop();
        }
    return res;
    }

private:
    unordered_map<int,int> map_;
    priority_queue<pair<int,int>, vector<pair<int,int>>, CompareByValue> p_que_;
};

int main() {
    Solution sol;
    vector<int> nums{1,1,1,2,2,3};
    int k = 2;
    vector<int> res = sol.topKFrequent(nums, k);
    for (const auto &item: res) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}
