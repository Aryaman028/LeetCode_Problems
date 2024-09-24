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
    vector<int> rightSideView(TreeNode* root) {
        //LEVEL ORDER TRAVERSAL
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int nodeatlevel = q.size();
            while(nodeatlevel){
                TreeNode* cur = q.front();
                if(cur!=NULL && nodeatlevel==1)v.push_back(cur->val);
                q.pop();
                if(cur!=NULL && cur->left)q.push(cur->left);
                if(cur!=NULL && cur->right)q.push(cur->right);
                nodeatlevel--;
            }
        }
        return v;
    }
};