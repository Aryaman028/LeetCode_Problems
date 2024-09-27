class Solution {
public:
    int c = 0;

    void traverse(TreeNode* root, long long curSum, int targetSum, unordered_map<long long, int>& m) {
        if (!root) return;

        // Update the current prefix sum
        curSum += root->val;

        // Check if there is a prefix sum that matches the targetSum
        if (curSum == targetSum) {
            c++;
        }

        if (m.find(curSum - targetSum) != m.end()) {
            c += m[curSum - targetSum];
        }

        // Add current sum to the map
        m[curSum]++;

        // Recursively traverse left and right subtrees
        traverse(root->left, curSum, targetSum, m);
        traverse(root->right, curSum, targetSum, m);

        // Backtrack: Remove current sum from the map to maintain prefix state
        m[curSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> m;
        traverse(root, 0, targetSum, m);
        return c;
    }
};
