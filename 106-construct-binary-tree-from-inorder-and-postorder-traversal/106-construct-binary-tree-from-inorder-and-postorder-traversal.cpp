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
    int postIdx;
    TreeNode* util(vector<int> &inorder, vector<int> &postorder, int left, int right){
        if(left>right) return NULL;
        TreeNode *root = new TreeNode(postorder[postIdx--]);
        int pos=-1;
        for(int i=left; i<=right; i++){
            if(root->val==inorder[i]){
                pos=i;
                break;
            }
        }
        root->right=util(inorder,postorder,pos+1,right);
        root->left=util(inorder,postorder,left,pos-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIdx=inorder.size()-1;
        return util(inorder,postorder,0,postIdx);
    }
};