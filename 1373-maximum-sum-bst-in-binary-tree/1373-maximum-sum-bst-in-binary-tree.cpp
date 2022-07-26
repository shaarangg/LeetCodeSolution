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
    int ans=0;
    vector<int> util(TreeNode *root){
        if(!root) return {INT_MAX,INT_MIN,0};
        vector<int> left=util(root->left);
        vector<int> right=util(root->right);
        if(left.empty() || right.empty() || root->val<=left[1] || root->val >= right[0]) return {};
        ans = max(ans, root->val+left[2]+right[2]);
        return {min(left[0],root->val),max(root->val,right[1]),root->val+left[2]+right[2]};
    }
    int maxSumBST(TreeNode* root) {
        util(root);
        return ans;
    }
};