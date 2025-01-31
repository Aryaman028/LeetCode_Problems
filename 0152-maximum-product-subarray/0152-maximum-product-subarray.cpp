class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int leftToRight = 1, rightToLeft = 1;
        int n = nums.size();
        int result = INT_MIN;

        for (int i = 0; i < n; i++) {
            leftToRight *= nums[i];
            rightToLeft *= nums[n - i - 1];

            result = max({result, leftToRight, rightToLeft});

            // Reset product if zero is encountered
            if (nums[i] == 0) leftToRight = 1;
            if (nums[n - i - 1] == 0) rightToLeft = 1;
        }
        return result;
    }
};
