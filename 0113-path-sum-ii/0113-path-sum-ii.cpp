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
    vector<vector<int>>res;
    void dfs(TreeNode* root, int targetSum,int curSum,vector<int>v){
        if(root==NULL)return;
        curSum += root->val;
        v.push_back(root->val);
        if(!root->left && !root->right && curSum==targetSum){
            res.push_back(v);
        }
        dfs(root->left,targetSum,curSum,v);
        // v.pop_back();
        dfs(root->right,targetSum,curSum,v);
        // v.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>v;
        dfs(root,targetSum,0,v);
        return res;
        
    }
};