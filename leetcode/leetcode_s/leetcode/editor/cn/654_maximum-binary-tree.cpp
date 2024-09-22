// 654 最大二叉树 2024-09-19 19:21:51

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

class Solution1 {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) {// 空节点
            return nullptr;
        }
        // 找最大值
        auto it = max_element(nums.begin(), nums.end());
        TreeNode* root = new TreeNode(*it);
        if (nums.size() == 1) { // 叶子结点
            return root;
        }
        // 分割数组
        vector<int> left(nums.begin(), it);
        vector<int> right(++it, nums.end());
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
    }
};

// 下标法
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        return traversal(nums, 0, nums.size());
    }

    // 左闭右开区间
    int findMax(vector<int>& nums, int start, int end) {
        int max = nums[start];
        int max_idx = start;
        for (int i = start + 1; i < end; i++) {
            if (nums[i] > max) {
                max = nums[i];
                max_idx = i;
            }
        }
        return max_idx;
    }

    TreeNode* traversal(vector<int>& nums, int start, int end) {
        if (start == end) {
            return nullptr;
        }
        int pivot = findMax(nums, start, end);
        TreeNode* root = new TreeNode(nums[pivot]);
        if (start - end == 1) {
            return root;
        }
        int left_start = start;
        int left_end = pivot;
        int right_start = pivot + 1;
        int right_end = end;
        root->left = traversal(nums, left_start, left_end);
        root->right = traversal(nums, right_start, right_end);

        return root;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
