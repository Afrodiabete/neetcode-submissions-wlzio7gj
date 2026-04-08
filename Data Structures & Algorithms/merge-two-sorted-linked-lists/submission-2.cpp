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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr= nullptr, *ans= nullptr;

        
        while(list1!= nullptr || list2!= nullptr){
            if(curr== nullptr){
                if(list1== nullptr){
                    curr= list2;
                    list2= list2->next;
                }
                else if(list2== nullptr){
                    curr= list1;
                    list1= list1->next;
                }
                else{
                    if(list1->val> list2->val){
                        curr= list2; list2= list2->next;
                    }
                    else{
                        curr= list1; list1= list1->next;
                    }
                }
                ans= curr;
            }
            else{
                if(list1== nullptr){
                    curr->next= list2;
                    curr= curr->next;
                    list2= list2->next;
                }
                else if(list2== nullptr){
                    curr->next= list1;
                    curr= curr->next;
                    list1= list1->next;
                }
                else{
                    if(list1->val> list2->val){
                        curr->next= list2; list2= list2->next;
                    }
                    else{
                        curr->next= list1; list1= list1->next;
                    }
                    curr= curr->next;
                }
            }
        }
        return ans;
    }
};
