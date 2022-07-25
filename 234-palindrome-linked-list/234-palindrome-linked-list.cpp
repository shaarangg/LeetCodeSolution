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
    ListNode *ptr;
    bool util(ListNode *head){
        if(!head) return true;
        bool temp = util(head->next);
        temp = temp && ptr->val==head->val;
        ptr=ptr->next;
        return temp;
    }
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ptr = head;
        return util(head);
    }
};