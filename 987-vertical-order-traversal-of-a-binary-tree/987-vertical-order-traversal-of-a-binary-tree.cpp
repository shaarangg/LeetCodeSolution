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
    map<int,vector<pair<int,int>>> dict;
    static bool cmp(pair<int,int> a, pair<int,int> b){
        if(a.second<b.second) return true;
        if(a.second==b.second && a.first<b.first) return true;
        return false;
    }
    void inorder(TreeNode *root,int row, int col){
        if(!root) return;
        dict[col].push_back({root->val,row});
        inorder(root->left,row+1,col-1);
        inorder(root->right,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        inorder(root,0,0);
        vector<vector<int>> ans;
        for(auto i: dict){
            sort(i.second.begin(),i.second.end(),cmp);
            vector<int> temp;
            for(auto j: i.second){
                temp.push_back(j.first);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};