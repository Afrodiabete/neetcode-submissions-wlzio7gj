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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr || q== nullptr){
            if(p==nullptr && q== nullptr){
                return true;
            }
            return false;
        }
        if(p->val!= q->val){
            return false;
        }
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) ?  true: false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(root== nullptr){
            return false;
        }
        if(root->val== subroot->val){
            if(isSameTree(root, subroot)== true) return true;
        }
        
        return isSubtree(root->left, subroot)||isSubtree(root->right, subroot)? true: false;
    }
};
