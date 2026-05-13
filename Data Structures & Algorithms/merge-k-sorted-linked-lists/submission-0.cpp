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
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        ListNode* ans= nullptr, *temp= nullptr;
        for(int i=0; i< lists.size(); i++){
            while(lists[i]!= nullptr){
                pq.push(new ListNode(lists[i]->val));
                lists[i]= lists[i]->next;
            }
        }
        if(!pq.empty()){
            temp= pq.top();
            pq.pop();
            ans= temp;
        }
        while(!pq.empty()){
            temp->next= pq.top();
            temp= temp->next;
            pq.pop();
        }
        return ans;
    }
};
