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
    void search(TreeNode* root, int prev_max, int& ans){
        if(root== nullptr) return;
        if(root->val>= prev_max) ans++;
        search(root->left, max(root->val, prev_max), ans);
        search(root->right, max(root->val, prev_max), ans);
        return;
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        search(root, -101, ans);
        return ans;
    }
};
