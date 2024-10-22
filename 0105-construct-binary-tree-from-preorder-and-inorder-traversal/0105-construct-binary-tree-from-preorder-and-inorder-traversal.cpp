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
    TreeNode* helperBuildTree(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend,unordered_map<int,int>&inmap){
        //base case
        if(prestart>preend || instart>inend)return NULL;

        //first ele of preoder will be the root
        TreeNode* root = new TreeNode(preorder[prestart]);

        //finding the root index in the indorder
        int rootIndex = inmap[root->val];

        //counting the ele in left subtree
        int leftsubtree = rootIndex-instart;
        
        //focusing on the left subtree think of only the left subtree and 
        //write for inorder nad preorder vector
        root->left = helperBuildTree(preorder,prestart+1,prestart+leftsubtree,inorder,instart,rootIndex-1,inmap);
        
        //same for the right subtree
        root->right = helperBuildTree(preorder,prestart+leftsubtree+1,preend,inorder,rootIndex+1,inend,inmap);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>inmap;
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }
        return helperBuildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmap);
    }
};