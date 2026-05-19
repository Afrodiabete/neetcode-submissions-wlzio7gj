/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // 改成回傳 int，代表「以當前節點為頂點，往下走的單向最大收益」
    int updateVal(TreeNode* node, int &ans) {
        if (node == nullptr) return 0;

        // 遞迴取得左右子樹的單向最大收益
        // 任務一：遇到負數貢獻不如不要走，直接用 max(0, ...) 歸零
        int left = max(0, updateVal(node->left, ans));
        int right = max(0, updateVal(node->right, ans));

        // 任務二：計算「V 字型」並挑戰全局最大值 ans (可以分岔)
        ans = max(ans, node->val + left + right);

        // 任務三：回傳「一字型」給父節點 (不能分岔，只能挑一邊最大的)
        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        // LeetCode 節點值可能很小，初始值設為足夠小的極端值
        int ans = -2147483648; 
        updateVal(root, ans);
        return ans;
    }
};