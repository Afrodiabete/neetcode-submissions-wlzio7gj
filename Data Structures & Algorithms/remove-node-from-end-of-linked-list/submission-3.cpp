/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next== nullptr) return nullptr;
        ListNode* l1= head, *l2= head, *prev= head;
        for(int i=0; i<n; i++){
            l2= l2->next;
        }
        if(l2== nullptr){
            head= head->next;
            return head;
        }
        while(l2!= nullptr){
            prev= l1;
            l1= l1->next;
            l2= l2->next;
        }
        cout << prev->val << endl;
        prev->next= prev->next->next;
        return head;
    }
};
