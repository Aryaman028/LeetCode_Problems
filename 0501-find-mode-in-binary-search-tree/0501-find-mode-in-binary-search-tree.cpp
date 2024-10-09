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
    unordered_map<int,int>m;
    void dfs(TreeNode* root){
        if(!root)return;
        m[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        //APPROACH USING HASHMAP
        dfs(root);
        int max_ele=INT_MIN;
        int res=0;
        vector<int>v;
        for(auto ele:m){
            if(ele.second>max_ele){
                max_ele=ele.second;
            }
        }
        for(auto ele:m){
            if(ele.second==max_ele){
                v.push_back(ele.first);
            }
        }
        // v.push_back(res);
        return v;
        
    }
};