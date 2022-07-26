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
    ListNode *merge(ListNode *left, ListNode *right){
        ListNode *ptr = new ListNode(0);
        ListNode *curr=ptr;
        while(left && right){
            if(left->val<right->val){
                curr->next=left;
                left=left->next;
            }
            else{
                curr->next=right;
                right=right->next;
            }
            curr=curr->next;
        }
        while(left){
            curr->next=left;
            curr=curr->next;
            left=left->next;
        }
        while(right){
            curr->next=right;
            curr=curr->next;
            right=right->next;
        }
        return ptr->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *temp=NULL,*slow=head,*fast=head;
        while(fast && fast->next){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;
        ListNode *left = sortList(head);
        ListNode *right = sortList(slow);
        return merge(left,right);
    }
};