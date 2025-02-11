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
    bool helper(TreeNode* root, long max,long min){
        if(root==NULL)return true;
        if(root->val >= max || root->val <= min)return false;

        return helper(root->left,root->val,min) &&
        helper(root->right,max,root->val);
    }

    bool isValidBST(TreeNode* root) {
        // if(root->val >= INT_MAX || root->val <= INT_MIN)return true;
        return helper(root,LONG_MAX,LONG_MIN);

    }
};