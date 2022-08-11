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
class Compare{
    public:
        bool operator () (ListNode *a, ListNode *b){
            return a->val>b->val;
        }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *,vector<ListNode *>,Compare> h;
        int k = lists.size();
        for(int i=0; i<k; i++){
            if(lists[i]) h.push(lists[i]);
        }
        ListNode *tail=new ListNode();
        ListNode *head = tail;
        while(!h.empty()){
            tail->next = h.top();
            h.pop();
            tail=tail->next;
            if(tail->next) h.push(tail->next);
            cout<<tail->val<<" ";
        }
        return head->next;
    }
};