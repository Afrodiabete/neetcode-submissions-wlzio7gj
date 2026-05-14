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
    void reverse(ListNode* &head, ListNode* &first, ListNode* &prev, ListNode* &next, int k){
        ListNode* p= prev, *f= first;
        while(f->next!= next){
            ListNode* temp= f->next;
            f->next= p;
            p= f;
            f= temp;
        }
        f->next= p;

        if(prev!= nullptr){
            prev->next= f;
        }
        else{
            head= f;
        }
        first->next= next;
        return;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count= 1;
        ListNode* track= head, * prev= nullptr, *first= head;
        while(track!= nullptr){
            if(count== k){
                ListNode* next= track->next;
                reverse(head, first, prev, next, k);
                prev= first;
                first= first->next;
                track= first;
                count= 1;
            }
            else{
                track= track->next;
                count++;
            }
            
        }
        return head;
    }
};
