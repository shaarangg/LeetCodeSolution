/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        unordered_map<Node*,Node*> dict;
        Node *newHead = new Node(head->val);
        dict[head]=newHead;
        Node *temp1=head->next, *temp2 = newHead;
        while(temp1){
            temp2->next = new Node(temp1->val);
            temp2 = temp2->next;
            dict[temp1] = temp2;
            temp1 = temp1->next;
        }
        temp1=head;
        temp2=newHead;
        while(temp1){
            temp2->random = dict[temp1->random];
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return newHead;
    }
};