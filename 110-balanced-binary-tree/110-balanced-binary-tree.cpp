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
    int util(TreeNode * root){
        if(!root) return 0;
        int left = util(root->left);
        int right = util(root->right);
        if(left==-1 || right==-1) return -1;
        if(abs(left-right)>1) return -1;
        return 1 + max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int x = util(root);
        if(x==-1) return false;
        return true;
    }
};