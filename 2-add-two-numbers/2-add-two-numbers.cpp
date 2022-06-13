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
        int carry=0;
        ListNode *head =l1, *temp=NULL;
        while(l1 && l2){
            temp=l1;
            l1->val = l1->val+l2->val+carry;
            if(l1->val>=10){
                carry=1;
                l1->val-=10;
            } else carry=0;
            l1 = l1->next;
            l2 = l2->next;
        }
    
        while(l1){
            temp=l1;
            l1->val = l1->val+carry;
            if(l1->val>=10){
                carry=1;
                l1->val-=10;
            } else carry=0;
            l1 = l1->next;
        } 
        l1 = temp;
        l1->next = l2;
        while(l2){
            l2->val+=carry;
            temp = l2;
            if(l2->val>=10){
                carry=1;
                l2->val-=10;
            } else carry=0;
            l2 = l2->next;
        }
        if(carry==1){
            temp->next = new ListNode(1);
        }
        return head;
    }
};