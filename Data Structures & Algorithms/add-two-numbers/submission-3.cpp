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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head= nullptr, *ans= nullptr, *temp= nullptr;
        int  carry= 0, val1= 0, val2= 0;
        while(l1!= nullptr || l2!= nullptr){
            l1== nullptr? val1= 0: val1= l1->val;
            l2== nullptr? val2= 0: val2= l2->val;
            if((val1+ val2+ carry) / 10 == 0){
                
                temp= new ListNode(val1+ val2+ carry);
                carry= 0;
            }
            else{
                
                temp= new ListNode((val1+ val2+ carry)% 10);
                carry= 1;
            }

            if(ans== nullptr) {
                ans= temp;
                head= ans;
            }
            else{
                ans->next= temp;
                ans= ans->next;
            }
            if(l1!= nullptr)
            l1= l1->next;
            if(l2!= nullptr)
            l2= l2->next;
        }
        if(carry== 1){
            temp= new ListNode(1);
            ans->next= temp;
        }
        return head;
    }
};
