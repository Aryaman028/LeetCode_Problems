class Solution {
public:
    
    int solve(int i, int prev, vector<int>&nums,vector<vector<int>>&dp){
        if(i==nums.size())return 0;

        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        
        int y=0;
        if(prev==-1 || nums[i]>nums[prev]){
            y = 1 + solve(i+1,i,nums,dp);
        }
        int x = solve(i+1,prev,nums,dp);

        return dp[i][prev+1] = max(x,y);
    }
    int lengthOfLIS(vector<int>& nums) {
        //Using take and not take approach and DP to store the previously come results in the array  
        //We will be storing the prev element in the variable so that we can pick the next ele which is greater than the prev ele
        // int n = nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return solve(0,-1,nums,dp);
        
        //using memoization now i am doing tabulation
        // int n = nums.size();
        // vector<vector<int>>dp(n + 1,vector<int>(n+1,0));

        // //conside the shift we have done for prev
        // for(int i = n - 1; i >= 0 ; i--){
        //     for(int prev = i - 1; prev >= -1; prev--){
        //         int y=0;
        //         if(prev==-1 || nums[i]>nums[prev]){
        //             //shifting the coordinates thus we are adding 1 to i in the column
        //             y = 1 + dp[i + 1][i + 1];
        //         }
        //         int x = dp[i+1][prev + 1];
        //         dp[i][prev+1] = max(x,y);

        //     }
        // }
        // return dp[0][0];

        //TOTALLY DIFFERENCT TABULATION APPROACH CANT BE BUILD BY OU OWN INTUITION

        // for each index count the longest increasing subsequence till that index

        int n = nums.size();
        vector<int>dp(n,1);

        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i]){
                    dp[i] = max(1 + dp[prev], dp[i]);
                }
            }
            maxi = max(dp[i],maxi);
        }
        
        return maxi;
    }
};