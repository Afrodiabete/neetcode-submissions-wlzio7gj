class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next; // 1. 先把原本的下一個節點存起來
            curr->next = prev;               // 2. 反轉：讓當前節點指向前方
            
            // 3. 指標向後移動一步
            prev = curr;                     
            curr = nextTemp;
        }
        
        // 當 curr 走到 nullptr 時，prev 剛好會停在原本的末尾節點（新的頭節點）
        return prev;
    }
};