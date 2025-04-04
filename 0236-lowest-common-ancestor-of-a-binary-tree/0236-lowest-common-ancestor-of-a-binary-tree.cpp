/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)return NULL;
        if(root == p)return p;
        if(root == q)return q;

        TreeNode* leftnode = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightnode = lowestCommonAncestor(root->right, p , q);

        if(leftnode && rightnode)return root;
        else{
            if(leftnode)return leftnode;
            if(rightnode)return rightnode;
            return NULL;
        }
        return root;
    }
};