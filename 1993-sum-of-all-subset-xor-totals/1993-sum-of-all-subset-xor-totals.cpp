class Solution {
public:
    void helper(int i, vector<int>& nums,int sum, int& tsum){
        if(i >= nums.size()){
            tsum += sum;
            return;
        }
        helper(i + 1, nums, sum ^ nums[i], tsum);
        helper(i + 1, nums, sum, tsum);
    }
    int subsetXORSum(vector<int>& nums) {
        // we will make subsets by using recursion
        int tsum = 0;
        helper(0, nums, 0, tsum);
        return tsum;
    }
};