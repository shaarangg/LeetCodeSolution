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
    int preIdx=0;
    TreeNode *util(vector<int> &preorder ,int left ,int right){
        if(left>right) return NULL;
        TreeNode *root = new TreeNode(preorder[preIdx]);
        preIdx++;
        if(left==right) return root;
        int pos=right+1;
        for(int i=left+1; i<=right; i++){
            if(root->val < preorder[i]){
                pos=i;
                break;
            }
        }
        root->left = util(preorder, left+1,pos-1);
        root->right = util(preorder, pos, right);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return util(preorder, 0,preorder.size()-1);
    }
};