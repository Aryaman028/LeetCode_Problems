class Solution {
public:
    // int memo(int row,int col , vector<vector<int>>&triangle,vector<vector<int>>&dp){
    //     if(row == triangle.size()-1)return dp[row][col] = triangle[row][col];

    //     if(dp[row][col]!=-1)return dp[row][col];
                
    //     int cur = triangle[row][col] + memo(row+1,col,triangle,dp);
    //     int cur1 = triangle[row][col] + memo(row+1,col+1,triangle,dp);

    //     return dp[row][col] = min(cur,cur1);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m =triangle[n-1].size();

        vector<vector<int>>dp(n,vector<int>(m,-1));

        // return memo(0,0,triangle,dp);

        //TABULATION

        //BASE CASE
        //taking all the col of the last row in the last row of dp as base case
        for(int i=0;i<n;i++){
            dp[n-1][i]=triangle[n-1][i];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){  //as it is a triangle 
                int d = triangle[i][j] + dp[i+1][j];
                int dr = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(d,dr);
            }
        }
        return dp[0][0];

    }
};