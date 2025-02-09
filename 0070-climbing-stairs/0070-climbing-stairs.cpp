class Solution {
public:
    int helper(int n,vector<int>&dp){
        if(n<0)return 0;
        if(n==0)return 1;

        if(dp[n]==-1) dp[n]=helper(n-1,dp)+helper(n-2,dp);

        return dp[n];
    }

    int climbStairs(int n) {
        //this solution caused me TLE as it is recursion
        //We can optimise it using DP

        // if(n<0)return 0;
        // if(n==0)return 1;

        // return climbStairs(n-1)+climbStairs(n-2);
        vector<int>dp(n+1,-1);
        return helper(n,dp);

    }
};

