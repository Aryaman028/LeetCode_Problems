class Solution {
public:
     int memo(int n, int sum, vector<int>&arr, vector<vector<int>>&dp){
        if(n == 0){
            if(arr[0] == 0 && sum == 0)return 2;
            if(sum == 0 || sum == arr[0])return 1;
            return 0;
        }
        
        if(dp[n][sum] != -1)return dp[n][sum];
        
        int pick = 0;
        
        if(sum >= arr[n]){
            pick = memo(n - 1,sum - arr[n], arr, dp);
        }
        int notPick = memo(n - 1, sum, arr, dp);
        
        return dp[n][sum] = pick + notPick;
          
    }
    int findTargetSumWays(vector<int>& arr, int target) {
        int n = arr.size();
        
        int tSum = 0;
        
        for(int i = 0; i < n;i++){
            tSum += arr[i];
        }
        
        if((tSum - target) % 2 != 0) return 0;
        
        int sum = (tSum - target) / 2;
        if(sum < 0)return 0;
        
        vector<vector<int>>dp(n, vector<int>(sum + 1, -1));
        
        return memo(n - 1, sum, arr,dp);
    }
};