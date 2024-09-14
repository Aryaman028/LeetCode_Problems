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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>res;
        if(root==NULL)return res;
        q.push(root);
        while(q.size()>0){
            int n = q.size();
            vector<int>v;
            for(int i=0;i<n;i++){
                TreeNode* cur = q.front();
                v.push_back(cur->val);
                q.pop();
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            res.push_back(v);
        }
        return res;
    }
}; 