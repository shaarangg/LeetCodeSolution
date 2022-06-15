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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        int len=0;
        ListNode *temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        k = k%len;
        if(len==0 || k==0) return head;
        k = len-k-1;
        temp = head;
        while(k--){
            temp = temp->next;
        }
        ListNode *newHead = temp->next;
        temp->next = NULL;
        temp = newHead;
        while(temp->next){
            temp = temp->next;
        }
        temp->next =head;
        return newHead;
    }
};