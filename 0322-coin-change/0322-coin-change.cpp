class Solution {
public:
    int memo(int n , int amount , vector<int>&coins,vector<vector<int>>&dp){
        //important base case
        if( n == 0 ){
            if(amount % coins[n] == 0) return amount / coins[n];
            return 1e9;
        } 

        if(dp[n][amount] != -1) return dp[n][amount];

        //pick
        int pick = INT_MAX;
        if(amount >= coins[n]) pick = 1 + memo(n,amount - coins[n], coins , dp);

        int notPick = memo(n-1 , amount, coins, dp);

        return dp[n][amount] =  min(pick,notPick);

        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(),coins.end());

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        int result = memo(n-1,amount,coins,dp);
        if(result >= 1e9 ) return -1;
        if(amount == 0) return 0;

        return result;
        
    }
};