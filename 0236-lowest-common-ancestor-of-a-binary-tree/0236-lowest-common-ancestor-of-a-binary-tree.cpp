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
    bool path(TreeNode* root, TreeNode* p, vector<TreeNode*>&v){
        if(root == NULL)return false;
        if(root == p){
            v.push_back(root);
            return true;
        }
        bool res = path(root->left, p, v) || path(root->right, p, v);
        if(res){
            v.push_back(root);
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>v1;
        vector<TreeNode*>v2;
        path(root,p,v1);
        path(root,q,v2);

        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());

        int i = 0;
        while(i < v1.size() && i < v2.size()){
            if(v1[i]!=v2[i]){
                break;
            }
            i++;
        }
        return v1[i - 1];
    }
};