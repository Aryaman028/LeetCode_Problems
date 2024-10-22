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
        long long sum=0;    //consider the constraints [use long long]
        while(!q.empty()){
            int level=q.size();
            //at each level
            while(level--){
                TreeNode* cur = q.front();
                q.pop();
                sum+=cur->val;
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            v.push_back(sum);
            sum=0;    //making it zero after pushing in vector as it will be adding 
        }


    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        //Doing the level order traversal on the tree and 
        //calculating the sum of the elements on the each level
        vector<long long>v;
        levelorder(root,v);
        sort(v.begin(),v.end());
        
        //finding kth largest sum

        for(int i=v.size()-1;i>=0;i--){
            k--;
            if(k==0){
                return v[i];
            }
        }
        return -1;
    }
};
