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
    ListNode *ptr = NULL;
    bool util(ListNode *head){
        if(!head) return true;
        bool res = util(head->next);
        if(ptr->val==head->val){
            ptr = ptr->next;
            return res && true;
        }
        return false;
    }
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ptr = head;
        return util(head);
    }
};