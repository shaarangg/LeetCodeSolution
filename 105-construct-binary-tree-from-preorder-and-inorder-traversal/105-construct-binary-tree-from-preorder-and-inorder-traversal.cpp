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
    TreeNode *util(vector<int> &preorder, vector<int> &inorder, int start, int end){
        if(start>end) return NULL;
        TreeNode *root = new TreeNode(preorder[preIdx++]);
        int pos=-1;
        for(int i=start; i<=end; i++){
            if(root->val==inorder[i]){
                pos=i;
                break;
            } 
        }
        root->left = util(preorder,inorder,start,pos-1);
        root->right =util(preorder,inorder,pos+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return util(preorder,inorder,0,inorder.size()-1);
    }
};