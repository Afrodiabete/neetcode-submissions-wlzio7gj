class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "N ";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr) {
                s += "N ";
            } else {
                s += to_string(node->val) + " ";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        stringstream ss(data);
        string s;
        
        // 1. 先獨立處理 Root (讀取第一個字串)
        ss >> s;
        if (s == "N") return nullptr; // 如果整棵樹是空的，直接回傳
        
        // 建立 Root 並推入佇列
        TreeNode* root = new TreeNode(stoi(s));
        queue<TreeNode*> q;
        q.push(root);
        
        // 2. 開始 BFS 拼裝
        while (!q.empty()) {
            // 從 Queue 拿出「父節點」
            TreeNode* parent = q.front();
            q.pop();
            
            // --- 讀取下一筆字串，作為父節點的「左」小孩 ---
            if (ss >> s) {
                if (s != "N") {
                    parent->left = new TreeNode(stoi(s));
                    q.push(parent->left); // 只有實體節點才需要進入 Queue 尋找它的下一代
                }
            }
            
            // --- 再讀取下一筆字串，作為父節點的「右」小孩 ---
            if (ss >> s) {
                if (s != "N") {
                    parent->right = new TreeNode(stoi(s));
                    q.push(parent->right);
                }
            }
        }
        
        return root;
    }
};