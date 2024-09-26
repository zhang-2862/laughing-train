// 108 将有序数组转换为二叉搜索树 2024-09-23 21:34:52

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

class Solution {
public:
    // 思路：与654.最大二叉树相同,此题不断选取区间中点作为根即可
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }

    TreeNode* traversal(vector<int>& nums, int start, int end) {
        cout << endl;
        cout << "(start,end): " << "(" << start << "," << end << ")" << endl;
        cout << endl;
        if (end == start) { // 区间大小为0
            cout << "--------" << endl;
            cout << "node: nullptr" << endl;
            cout << "--------" << endl;
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        cout << "--------" << endl;
        cout << "node: " << nums[mid] << endl;
        cout << "--------" << endl;
        TreeNode* root = new TreeNode(nums[mid]); // 将根节点构造出来
        // if (end - start == 1) { //区间大小为1 此时为叶子结点
        //     return root;
        // }
        root->left = traversal(nums, start, mid);
        root->right = traversal(nums, mid +1, end);
        return root;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
