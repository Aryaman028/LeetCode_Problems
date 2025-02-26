class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount;
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];

                // If the product has been seen before, add 8 * previous occurrences
                count += productCount[product] * 8;

                // Increment the count for this product
                productCount[product]++;
            }
        }

        return count;
    }
};
