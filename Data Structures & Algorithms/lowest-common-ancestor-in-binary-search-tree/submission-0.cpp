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
    TreeNode* search(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root== nullptr) return nullptr;
        if(root->val< p->val && root->val< q->val){
            return search(root->right, p, q);
        }
        else if(root->val> p->val && root->val> q->val){
            return search(root->left, p , q);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return search(root, p, q);
    }
};
