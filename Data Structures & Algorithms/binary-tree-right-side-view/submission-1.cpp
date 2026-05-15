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
    void level(vector<vector<int>> &ans, TreeNode* root, int floor){
        if(root== nullptr) return;
        if(floor>= ans.size()) ans.resize(floor+1);
        ans[floor].push_back(root->val);
        level(ans, root->left, floor+1);
        level(ans, root->right, floor+1);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int>final;
        level(ans, root, 0);
        for(auto a: ans){
            final.push_back(a.back());
        }
        return final;
    }
};
