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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        int l1=0;
        int l2=0;
        ListNode *temp=headA;
        while(temp){
            l1++;
            temp = temp->next;
        }
        temp=headB;
        while(temp){
            temp = temp->next;
            l2++;
        }
        if(l1>=l2){
            int l3 = l1-l2;
            for(int i=0; i<l3; i++) headA = headA->next;
            while(headA && headB){
                if(headA==headB) return headA;
                headA = headA->next;
                headB = headB->next;
            }
        } else{
            int l3 = l2-l1;
            for(int i=0; i<l3; i++) headB = headB->next;
            while(headA && headB){
                if(headA==headB) return headA;
                headA = headA->next;
                headB = headB->next;
            }
        }
        return NULL;
    }
};