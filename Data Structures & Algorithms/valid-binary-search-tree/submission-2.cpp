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
    bool check(TreeNode* root, int upper, int lower){
        if(root== nullptr) return true;
        if(root->val>= upper || root->val<= lower) return false;
        return check(root->left, root->val, lower) && check(root->right, upper, root->val);
    }
    bool isValidBST(TreeNode* root) {
        return check(root, 1001, -1001);
    }
};
