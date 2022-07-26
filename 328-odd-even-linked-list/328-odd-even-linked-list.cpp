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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return NULL;
        int i=1;
        ListNode *odd=NULL,*even=NULL,*evenHead=NULL,*ptr=head;
        while(ptr){
            if(i%2!=0){
                if(odd==NULL) odd=ptr;
                else{
                    odd->next=ptr;
                    odd=odd->next;
                }    
            }
            else{
                if(even==NULL){
                    even = ptr;
                    evenHead=even;
                } 
                else{
                    even->next=ptr;
                    even=even->next;
                } 
            }
            ptr=ptr->next;
            i++;
        }
        if(even) even->next=NULL;
        odd->next=evenHead;
        return head;
    }
};