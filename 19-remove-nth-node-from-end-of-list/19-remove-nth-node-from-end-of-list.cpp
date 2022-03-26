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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = 0;
        ListNode *temp = head;
        while(temp){
            l++;
            temp = temp->next;
        } 
        int idx = l-n;
        if(idx==0){
            temp=head;
            head = head->next;
            delete(temp);
            return head;
        }
        else{
            ListNode *prev=NULL;
            temp = head;
            while(idx>0){
                prev=temp;
                temp=temp->next;
                idx--;
            }
            prev->next=temp->next;
            delete(temp);
            return head;
        }
    }
};