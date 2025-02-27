class Solution {
public:
    int memo(int row,int col , vector<vector<int>>&triangle,vector<vector<int>>&dp){
        if(row == triangle.size()-1)return dp[row][col] = triangle[row][col];

        if(dp[row][col]!=-1)return dp[row][col];
                
        int cur = triangle[row][col] + memo(row+1,col,triangle,dp);
        int cur1 = triangle[row][col] + memo(row+1,col+1,triangle,dp);

        return dp[row][col] = min(cur,cur1);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m =triangle[n-1].size();
        
        vector<vector<int>>dp(triangle.size(),vector<int>(m,-1));

        return memo(0,0,triangle,dp);
    }
};