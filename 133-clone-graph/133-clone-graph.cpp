/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node *> dict;
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(dict.find(node)==dict.end()){
            Node *newNode = new Node(node->val);
            dict[node]=newNode;
            for(auto i: node->neighbors){
                newNode->neighbors.push_back(cloneGraph(i));
            }
            return newNode;
        }
        return dict[node];
    }
};