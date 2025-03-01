class Solution {
public:
    int memo(int n , int amount , vector<int>&coins,vector<vector<int>>&dp){
        if(n==0){
            if(amount % coins[n] == 0) return amount / coins[n];
            return 1e9;
        }
        
        if(dp[n][amount] != -1) return dp[n][amount];
        int pick = INT_MAX;

        if(amount >= coins[n]){
            pick = 1 + memo(n, amount - coins[n], coins, dp);
        }
        int notPick = memo(n-1, amount , coins, dp);

        return dp[n][amount] = min(pick,notPick);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(),coins.end());

        // vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        // int result = memo(n-1,amount,coins,dp);
        // if(result >= 1e9 ) return -1;
        // if(amount == 0) return 0;


        //TABULATION
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        //BASE CASE
        for(int i = 0;i <= amount ;i++){
            
            if(i % coins[0] == 0){
                dp[0][i] = i / coins[0];
            }else dp[0][i] = 1e9;
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= amount ;j++){

                int pick = (j >= coins[i]) ? 1 + dp[i][j - coins[i]] : INT_MAX ;
            
                int notPick = dp[i-1][j];

                dp[i][j] = min(pick,notPick);
            }
        }
        int result = dp[n-1][amount];

        if(result >= 1e9 ) return -1;
        return result;
        
    }
};