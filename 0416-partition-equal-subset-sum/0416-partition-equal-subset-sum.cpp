class Solution {
public:

    //MEMOIZATION
    bool check(int n, int target, vector<int>&nums , vector<vector<int>>&dp){
        if(target == 0)return true;
        if(n == 0) return target == nums[0];

        if(dp[n][target] != -1)return dp[n][target];
        //take
        bool take=false;
        if(target >= nums[n]) take = check(n-1,target - nums[n], nums, dp);
        bool notTake = check(n - 1,target,nums,dp);

        return dp[n][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }

        if(totalSum % 2 != 0){
            return false;
        }

        int sum = totalSum/2;

        // check the sum as we did in the subset sum
        // vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        // return check(n-1,sum,nums,dp);

        //TABULATION
        vector<vector<bool>>dp(n,vector<bool>(sum+1,0));

        // BASECASE
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        if(nums[0]<=sum)dp[0][nums[0]] = true;

        for(int i = 1; i < n; i++){
            for(int target = 1; target <= sum; target++ ){
                bool take=false;
                if(target >= nums[i]) take = dp[i-1][target - nums[i]];
                bool notTake = dp[i - 1][target];

                dp[i][target] = take || notTake;
            }
        }

        return dp[n-1][sum];


    }
};