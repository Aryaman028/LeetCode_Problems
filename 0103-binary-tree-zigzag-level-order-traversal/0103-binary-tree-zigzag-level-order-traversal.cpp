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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>q;

        vector<vector<int>>res;
        q.push(root);
        int lvl = 1;
        while(!q.empty()){
            int n = q.size();
            vector<int>v;
            while(n--){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);

                v.push_back(cur->val);
            }
            if(lvl % 2 == 0){
                reverse(v.begin(),v.end());
            }
            lvl++;
            res.push_back(v);   
        }
        return res;
    }
};