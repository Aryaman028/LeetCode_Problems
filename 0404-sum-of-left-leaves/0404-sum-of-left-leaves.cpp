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
    int sumOfLeftLeaves(TreeNode* root) {
       queue<TreeNode*>q;
       q.push(root);
       int sum=0;
       while(!q.empty()){
            int n= q.size();
            while(n--){
                TreeNode* cur = q.front();
                if(cur && cur->left && cur->left->left==NULL && cur->left->right==NULL)sum+=cur->left->val;
                q.pop();
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
       }
       return sum;
    }
};