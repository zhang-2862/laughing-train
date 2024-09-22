// 501 二叉搜索树中的众数 2024-09-21 17:28:34

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
#if 0

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

struct Compare {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    }
};

// 思路为中序遍历，存到map后排序 (适用于任意二叉树）
class Solution1 {
public:
    map<int, int> map; //<val, frequency>
    vector<int> findMode(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> res;
        inOrder(root);
        vector<pair<int, int>> v(map.begin(), map.end());
        sort(v.begin(), v.end(), Compare());
        // 先获取第一个最高频元素的频率
        int max_k = v.begin()->second;
        auto it = v.begin();
        for (; it != v.end() && it->second == max_k; ++it) {
            res.push_back(it->first);
        }
        return res;
    }

    void inOrder(TreeNode* cur) {
        if (cur == nullptr) {
            return;
        }
        inOrder(cur->left);
        map[cur->val]++;
        inOrder(cur->right);
    }
};

// 中序遍历法 加 pre 指针 加 clear清空vector 一次遍历求众数
class Solution {
public:
    int max_count = 0;
    int count = 0;
    vector<int> res;
    TreeNode* pre = nullptr;
    vector<int> findMode(TreeNode* root) {
        if (root == nullptr) {
            return {}; // 直接返回空
        }
        inOrder(root);
        return res;
    }

    void inOrder(TreeNode* cur) {
        if (!cur) {
            return;
        }
        inOrder(cur->left);
        // 处理结点
        if (!pre) {// pre为空
            count = 1;
        } else if (cur->val == pre->val) {
            // 如果当前结点值与上一个结点值相同
            count++;
        } else {
            // 不同则重置count
            count = 1;
        }
        // 更新pre
        pre = cur;
        // 如果当前计数跟最大值一致则将该值加入结果集
        if (count == max_count) {
            res.push_back(cur->val);
        }
        // 若计数已大于最大值，则更新最大值，并且清空之前的结果集，将该值加入结果集
        if (count > max_count) {
            max_count = count;
            res.clear();
            res.push_back(cur->val);
        }
        inOrder(cur->right);
    }
};

//leetcode submit region end(Prohibit modification and deletion)
