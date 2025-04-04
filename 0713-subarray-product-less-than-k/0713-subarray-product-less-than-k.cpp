class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //I WILL BE USING SLIDING WINDOW AND GO TO THAT INDEX TILL WHERE THE SUBARRAY IS VALID THEN I WILL COUNT THE LENGTH OF THE SUBARRAY THEN COUNT THE SUBARRAYS IT CAN FORM ADD IT TO THE RES;

        int i = 0, j = 0;
        if(k <= 1)return 0;
        int n = nums.size();
        long long pro = 1;
        int count = 0;
        while(j < n){
            pro *= nums[j];
            while(i < n && pro >= k){
                pro = pro / nums[i];
                i++;
            }
            if(i <= j){
                int len = j - i + 1;
                count += len;
            }
            j++;
        }
        return count;
    }
};