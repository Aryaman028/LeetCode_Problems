class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int sum = nums[0];
        int max_sum = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i])sum+=nums[i];    //adding new ele to subarray
            if(nums[i-1]>=nums[i])sum=nums[i];    //starting new subarray
            max_sum = max(sum,max_sum);
        }
        return max_sum;

        
    }
};