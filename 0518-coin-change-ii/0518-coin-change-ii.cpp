class Solution {
public:
    int memo(int ind , int amount, vector<int>&coins ,vector<vector<int>>&dp){
        if(amount == 0) return 1;
        if(ind == 0){
                if(amount >= coins[0]){
                    return memo(ind,amount - coins[ind], coins,dp);
                }
                return 0;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];

        int pick = (amount >= coins[ind]) ? memo(ind, amount - coins[ind], coins, dp) : 0;
        int notPick = memo(ind - 1, amount, coins , dp);

        return  dp[ind][amount] = pick + notPick;

    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return memo(n-1,amount,coins,dp);
        
    }
};