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
    unordered_map<int,int>m;
    void postorder(TreeNode* root,int l){
        if(root == NULL)return;

        m[root->val] = l;
        postorder(root->left,l+1);
        postorder(root->right, l+1);
    }

    TreeNode* lca(TreeNode* root, int depth){
        if(root == NULL || m[root->val] == depth)return root;

        TreeNode* leftnode = lca(root->left, depth);
        TreeNode* rightnode = lca(root->right, depth);

        //if both are not null then we got the lca
        if(leftnode && rightnode)return root;
        else{
            if(leftnode)return leftnode;
            if(rightnode)return rightnode;
            return NULL;
        }
        return root;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {

        //BASIC APPROACH

        //Using dfs or bfs any approach find the last level nodes
        // Using dfs store the l with the node in a pair
        // then for each node in the vector find the path of the node and store all the paths in the 2d vector and find the size of row which is smallest otherwise we will get Out of boundation error then compute using same Lowest common ancestor

        // OPTIMAL APPROACH

        //first of all find the the max depth
        // using postorder or any order
        
        postorder(root, 0);
        int depth = 0;
        //we got the depth of the leaf nodes
        for(auto ele: m){
            depth = max(depth, ele.second);
        }
        return lca(root,depth);
        return NULL;
    }
};