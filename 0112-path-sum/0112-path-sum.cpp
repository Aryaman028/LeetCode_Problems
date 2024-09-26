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
    bool flag = false;
    void dfs(TreeNode* root, int targetSum,int curSum){
        if(root==NULL)return;
        curSum+=root->val;
        if(!root->left && !root->right && curSum==targetSum)flag = true;
        dfs(root->left,targetSum,curSum);
        dfs(root->right,targetSum,curSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum,0);
        return flag;
    }
};