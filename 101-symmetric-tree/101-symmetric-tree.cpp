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
    bool util(TreeNode *left, TreeNode *right){
        if(!left || !right) return right==left;
        return left->val==right->val && util(left->left, right->right) && util(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return root && util(root->left, root->right);
    }
};