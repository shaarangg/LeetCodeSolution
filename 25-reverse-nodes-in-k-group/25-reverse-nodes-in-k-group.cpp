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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode *ptr=head, *prev=NULL,*end=head;
        int K=k;
        while(head && K){
            ptr = ptr->next;
            head->next = prev;
            prev=head;
            head = ptr;
            K--;
        }
        if(K==0) end->next = reverseKGroup(head,k);
        else{
            return reverseKGroup(prev,k-K);
        }
        return prev;
    }
};