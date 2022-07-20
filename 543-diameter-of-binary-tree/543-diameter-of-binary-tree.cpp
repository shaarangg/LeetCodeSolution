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
    int util(TreeNode *root, int &mx){
        if(!root) return 0;
        int left = util(root->left,mx);
        int right=util(root->right,mx);
        if(mx<left+right) mx = left+right;
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int mx=0;
        util(root,mx);
        return mx;
    }
};