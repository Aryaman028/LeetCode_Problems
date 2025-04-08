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

    int helperFunction(TreeNode* root,int &res){
        if(root==NULL)return NULL;
        int left = helperFunction(root->left,res);
        int right = helperFunction(root->right,res);
        res = max(res,left+right);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res=0;
        int v=helperFunction(root,res);
        return res;
    }
};