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
    void levelorder(TreeNode* root,vector<long long>&v){
        queue<TreeNode*>q;
        q.push(root);
        long long sum=0;
        while(!q.empty()){
            int level=q.size();
            while(level--){
                TreeNode* cur = q.front();
                q.pop();
                sum+=cur->val;
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            v.push_back(sum);
            sum=0;
        }


    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>v;
        levelorder(root,v);
        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>=0;i--){
            k--;
            if(k==0){
                return v[i];
            }
        }
        return -1;
    }
};