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
    vector<string>v;
    void dfs(TreeNode* root,string str){
        if(!root)return;
        str+=to_string(root->val);
        if(!root->left && !root->right){
            v.push_back(str);
        }else str+="->";
        dfs(root->left,str);
        dfs(root->right,str);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,"");
        return v;
        
    }
};