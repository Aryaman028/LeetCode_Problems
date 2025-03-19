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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
         if(root==NULL)return {};

        queue<TreeNode*>q;
        q.push(root);

        vector<vector<int>>res;

        while(!q.empty()){
           
            int n = q.size();
            vector<int>v;
            
            while(n){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur -> right){
                    q.push(cur->right);
                }
                v.push_back(cur->val);
                n--;
            }
            res.push_back(v);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};