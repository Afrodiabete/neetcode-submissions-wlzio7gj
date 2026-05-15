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
    void inorder(TreeNode* root, int &num, int k, int &ans){
        if(root== nullptr) return;
        inorder(root->left, num, k, ans);
        if(num==k) {
            ans= root->val;
            num++;
            return;
        }
        else{
            num++;
        }
        inorder(root->right, num, k, ans);
        
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        int num=1, ans=0;
        inorder(root,num, k, ans);
        return ans;
    }
};
