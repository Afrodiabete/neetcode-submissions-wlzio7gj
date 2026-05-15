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
private:
    unordered_map<int, int> inorder_map;
    int preorder_idx = 0;

    TreeNode* build(vector<int>& preorder, int in_start, int in_end) {
        // 邊界條件：當區間無效時，代表該子樹為空
        if (in_start > in_end) return nullptr;

        // 1. 從 preorder 取得當前子樹的 root 數值
        int root_val = preorder[preorder_idx++];
        TreeNode* root = new TreeNode(root_val);

        // 2. 找到該 root 在 inorder 中的位置
        int mid = inorder_map[root_val];

        // 3. 遞迴建立左子樹與右子樹
        // 注意：依據 preorder 的順序 [Root -> 左 -> 右]，必須先遞迴建立左子樹
        root->left = build(preorder, in_start, mid - 1);
        root->right = build(preorder, mid + 1, in_end);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inorder_map.clear();
        preorder_idx = 0;

        // 預先紀錄 inorder 的值與索引對應，將尋找時間優化至 O(1)
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size() - 1);
    }
};