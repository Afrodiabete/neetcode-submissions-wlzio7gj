/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        calculateDepth(root, maxDiameter);
        return maxDiameter;
    }

private:
    int calculateDepth(TreeNode* node, int& maxDiameter) {
        if (!node) return 0;

        // 遞迴計算左右子樹深度
        int leftDepth = calculateDepth(node->left, maxDiameter);
        int rightDepth = calculateDepth(node->right, maxDiameter);

        // 更新全域最大直徑：左深度 + 右深度
        maxDiameter = max(maxDiameter, leftDepth + rightDepth);

        // 回傳該節點的高度給上一層（父節點）使用
        return max(leftDepth, rightDepth) + 1;
    }
};