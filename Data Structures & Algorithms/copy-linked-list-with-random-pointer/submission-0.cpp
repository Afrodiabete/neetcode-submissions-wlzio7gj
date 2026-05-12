class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        // 建立一個映射表：舊節點地址 -> 新節點地址
        unordered_map<Node*, Node*> m;
        
        // 第一遍遍歷：建立所有新節點，並存入 map
        Node* curr = head;
        while (curr) {
            m[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        // 第二遍遍歷：根據 map 設定新節點的 next 與 random
        curr = head;
        while (curr) {
            // m[curr] 是當前的新節點
            // m[curr->next] 是下一個新節點
            m[curr]->next = m[curr->next]; 
            // m[curr->random] 是對應隨機位置的新節點
            m[curr]->random = m[curr->random];
            curr = curr->next;
        }
        
        return m[head];
    }
};