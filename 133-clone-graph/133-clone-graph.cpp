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
    unordered_map<Node*, Node*> dict;
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(dict.find(node)==dict.end()){
            dict[node]=new Node(node->val);
            for(auto adj: node->neighbors){
                dict[node]->neighbors.push_back(cloneGraph(adj));
            }
        }
        return dict[node];
    }
};