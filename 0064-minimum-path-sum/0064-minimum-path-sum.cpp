class Solution {
public:
    // int memo(int i,int j,int n,int m,vector<vector<int>>& grid){
    //     if(i>m || j>n)return 0;

    //     if(i==m-1 || j==n-1){
    //         mini = min(mini,sum);
    //         return
    //     }
    //     int sum =0;

    //     int x = memo(m-1,n,grid);
    //     int y = memo(m,n-1,grid);

    //     return sum + min(x,y);
    // }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // dp[0][0] = grid[0][0];

        for(int row =0; row<m; row++){
            for(int col = 0; col < n; col++){

                if(row==0 && col==0)dp[row][col] =grid[row][col];
                else if(row==0){
                    dp[row][col] = grid[row][col] + dp[row][col-1];
                }else if(col==0){
                    dp[row][col] = grid[row][col] + dp[row-1][col];
                }else{
                    dp[row][col] = grid[row][col] + min(dp[row-1][col],dp[row][col-1]);
                }
            }
        }
        return dp[m-1][n-1];
    }
};