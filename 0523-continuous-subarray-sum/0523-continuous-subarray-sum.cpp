class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // If (prefixSum[j] - prefixSum[i]) % k == 0, then nums[i+1] to nums[j] forms a valid subarray;
        //then This means: if two prefix sums have the same remainder when divided by k, the subarray between them has a sum that is a multiple of k.


        unordered_map<int,int>m;
         m[0] = -1; // Important: Handles subarrays starting from index 0
        vector<int>pre(nums.size());
        pre[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            pre[i] = pre[i - 1] + nums[i];
        }

        int count = 0;
        for(int i = 0;i < pre.size(); i++){
            int val = pre[i] % k;

             // Handle negative remainder case
            if (val < 0) val += k;

            if(m.count(val) > 0){
                if(i - m[val] >= 2)
                    return true;
            }else m[val] = i;
            
        }
        return false;
    }
};