/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root) return "X";
        string sl="";
        queue<TreeNode *> q;
        q.push(root);
        sl+=to_string(root->val)+" ";
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                sl+=to_string(node->left->val)+" ";
            }
            if(!node->left){
                sl+="X ";
            }
            if(node->right){
                q.push(node->right);
                sl+=to_string(node->right->val)+" ";
            }
            if(!node->right){
                sl+="X ";
            }
        }
        cout<<sl;
        return sl;
    }
    
    TreeNode* deserialize(string s) {
        stringstream ss(s);
        string node;
        ss >> node;
        if(node=="X") return NULL;
        TreeNode *root = new TreeNode(stoi(node));
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            ss >> node;
            if(node!="X"){
                temp->left = new TreeNode(stoi(node));
                q.push(temp->left);
            }
            ss >> node;
            if(node!="X"){
                temp->right = new TreeNode(stoi(node));
                q.push(temp->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));