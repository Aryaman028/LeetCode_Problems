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
    TreeNode* construct(vector<int>& preorder,int preStart,int preEnd, vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int>&m){
        if(preStart>preEnd || inStart>inEnd)return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        //find index of root in inorder
        int index = m[preorder[preStart]];
        int count = index - inStart;

        root->left = construct(preorder,preStart+1,preStart+count,inorder,inStart,index-1,m);
        root->right = construct(preorder,preStart+1+count,preEnd,inorder,index+1,inEnd,m);
        return root;

        
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        unordered_map<int,int>m;

        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        return construct(preorder,0,n-1,inorder,0,n-1,m);
    }
};