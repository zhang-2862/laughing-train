#include <iostream>
#include <vector>
#include <deque>
#include <set>

using namespace std;

class Solution {
private:
    class MonotonicQueue {
    public:
        void pop(int value) {
            if (!que_.empty() && value == que_.front()) {
                que_.pop_front();
            }
        }

        void push(int value) {
            while (!que_.empty() && value > que_.back()) {
                que_.pop_back();
            }
            que_.push_back(value);
        }

        int front() {
            return que_.front();
        }

    private:
        deque<int> que_;
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue que;
        vector<int> res;
        res.reserve(nums.size() - k + 1);
        // 初始窗口入队
        for (int i = 0; i < k; ++i) {
           que.push(nums[i]);
        }
        res.push_back(que.front());// 将初始窗口的最大值存入结果集

        for (int i = k; i < nums.size(); ++i) {
            que.push(nums[i]);
            que.pop(nums[i - k]);
            res.push_back(que.front());
        }
        return res;
    }
};

// multiset解决
class MultisetSolution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        res.reserve(nums.size() - k + 1);
        // 初始窗口入队
        for (int i = 0; i < k; ++i) {
            set_.insert(nums[i]);
        }
        res.push_back(*set_.rbegin());// 将初始窗口的最大值存入结果集

        for (int i = k; i < nums.size(); ++i) {
            set_.erase(set_.find(nums[i-k]));
            set_.insert(nums[i]);
            res.push_back(*set_.rbegin());
        }
        return res;
    }

private:
    multiset<int> set_;
};

int main() {
    Solution sol;
    vector<int> v = {1,3,-1,-3,5,3,6,7};
//    vector<int> res = sol.maxSlidingWindow(v,3);

    MultisetSolution mssol;
    vector<int> res = mssol.maxSlidingWindow(v, 3);
    for (const auto &item: res) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
