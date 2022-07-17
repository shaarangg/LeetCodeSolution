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
        int T=k;
        ListNode *prev=NULL,*ptr=head,*nxt=NULL,*end=head;
        while(T && ptr!=NULL){
            nxt = ptr->next;
            ptr->next=prev;
            prev=ptr;
            ptr = nxt;
            T--;
        }
//         head = prev
        if(T!=0){
            prev = reverseKGroup(prev,k-T);
        } else{
            end->next = reverseKGroup(nxt,k);    
        }
        
        
        
        return prev;
    }
};