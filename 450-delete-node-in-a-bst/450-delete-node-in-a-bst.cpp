/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(key<root->val){
            root->left=deleteNode(root->left,key);
        } 
        else if(root->val==key){
            if(!root->left && !root->right) return NULL;
            if(!root->right || !root->left) return root->left?root->left:root->right;
            else{
                TreeNode *ptr = root->left;
                while(ptr->right) ptr = ptr->right;
                root->val = ptr->val;
                root->left = deleteNode(root->left,ptr->val);
            }
        } else root->right=deleteNode(root->right,key);
        return root;
    }
};