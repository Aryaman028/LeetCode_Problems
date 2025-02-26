class Solution {
public:
    // int memo(int m,int n,vector<vector<int>>& grid,vector<vector<int>>&dp){
    //     if(n<0 || m<0)return 1e9;
    //     if(n==0 && m==0)return grid[0][0];

    //     if(dp[m][n]!=-1)return dp[m][n];

    //     int x = grid[m][n] + memo(m-1,n,grid,dp);
    //     int y = grid[m][n] + memo(m,n-1,grid,dp);

    //     return  dp[m][n] = min(x,y);
    // }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // return memo(m-1,n-1,grid,dp);

        // TABULATION 
        for(int row =0; row<m; row++){
            for(int col = 0; col < n; col++){

                if(row==0 && col==0)dp[row][col] =grid[row][col];
                else{
                    int up =1e7,left=1e7;
                    if(row>0){
                        up = dp[row-1][col];
                    }
                    if(col>0){
                        left = dp[row][col-1];
                    }
                    dp[row][col] = grid[row][col] + min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};