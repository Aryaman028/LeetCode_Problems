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
    bool path(TreeNode* root, TreeNode* p,vector<TreeNode*>&v){
            if(root==NULL)return false;
            if(root->val==p->val){
                v.push_back(root);
                return true;
            }

            bool res = path(root->left,p,v) || path(root->right,p,v);
            if(res){
                v.push_back(root);
                return true;
            }
            
            return false;
        }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //in this we have to find the path of the each ele and store it in an array and then compare both the arrays.
        vector<TreeNode*>v1;
        vector<TreeNode*>v2;
        path(root,p,v1);
        path(root,q,v2);

        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());

        int i=0,j=0;
        //using pointers check where you found the common ancestor
        TreeNode* ans = new TreeNode();
        while(i<v1.size() && j<v2.size()){
            if(v1[i]==v2[j]){
                ans = v1[i];
                i++;
                j++;
            }
            else break;
        }
        return ans;

    }
};