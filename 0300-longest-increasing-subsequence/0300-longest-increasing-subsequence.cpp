class Solution {
public:
    
    int solve(int i, int front, vector<int>&nums,vector<vector<int>>&dp){
        if(i < 0){
            return 0;
        }

        if(dp[i][front]!=-1)return dp[i][front];
        
        //pick
        int y=0;
        if(front == nums.size() || nums[i] < nums[front]){//we will be counting in y whenever we are picking the right ele
            y = 1 + solve(i - 1, i, nums, dp);
        }
        //not pick
        int x = solve(i - 1, front, nums, dp);


        return dp[i][front] = max(x,y);
    }
    int lengthOfLIS(vector<int>& nums) {
        //Using take and not take approach and DP to store the previously come results in the array  
        //We will be storing the prev element in the variable so that we can pick the next ele which is greater than the prev ele
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));

        //TABULATION

        return solve(n - 1 , n, nums, dp);
    }
};