/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL or head->next==NULL){
        return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* stop = head;
            while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                while(slow!=stop){
                    slow = slow->next;
                    stop = stop->next;
                }
                return slow;
            }
        } 
        return NULL;
    }
};