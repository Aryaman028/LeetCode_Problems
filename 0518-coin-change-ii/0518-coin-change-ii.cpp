class Solution {
public:

    // MEMOIZATION 
    int memo(int ind , int amount, vector<int>&coins ,vector<vector<int>>&dp){
        //most important base case
        if(ind == 0){
                return (amount % coins[0] == 0);
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];

        int pick = (amount >= coins[ind]) ? memo(ind, amount - coins[ind], coins, dp) : 0;
        int notPick = memo(ind - 1, amount, coins , dp);

        return  dp[ind][amount] = pick + notPick;

    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<long long>>dp(n,vector<long long>(amount+1,0));
        // return memo(n-1,amount,coins,dp);

        //TABULATION

        // BASE CASE
        // on ind == 0 amount can be anything, thus putting the value which is returning in the base case as value
   
        vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount + 1, 0));

        for (int i = 0; i <= amount; i++) {
            dp[0][i] = (i % coins[0] == 0);
        }

        for (int ind = 1; ind < n; ind++) {
            for (int t = 0; t <= amount; t++) {
                unsigned long long notPick = dp[ind - 1][t];  // Not using current coin
                unsigned long long pick = (t >= coins[ind]) ? dp[ind][t - coins[ind]] : 0;  // Using current coin

                dp[ind][t] = pick + notPick;
            }
        }
        return dp[n - 1][amount];
    }
};