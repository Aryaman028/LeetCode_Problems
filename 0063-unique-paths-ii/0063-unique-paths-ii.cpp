class Solution {
public:
    int memo(int m, int n,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
        //base case
        if(m<0 || n<0 || obstacleGrid[m][n]==1){
            return 0;
        }
        //when it comes to the top left corner
        if(m==0 && n==0)return 1;

        //if we have already calculated the dp[m][n] then return
        if(dp[m][n]!=-1)return dp[m][n];

        return dp[m][n] = memo(m-1,n,obstacleGrid,dp) + memo(m,n-1,obstacleGrid,dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // return memo(m-1,n-1,obstacleGrid,dp);

        //TABULATION
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(obstacleGrid[row][col]==1){
                    dp[row][col]=0;
                }
                else if(row==0 && col==0){
                    dp[row][col]=1;
                }else{
                    int up=0 , left =0;
                    if(row>0){
                        up=dp[row-1][col];
                    }
                    if(col>0){
                        left = dp[row][col-1];
                    }
                    dp[row][col] = up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};