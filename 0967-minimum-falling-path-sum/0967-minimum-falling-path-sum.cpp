class Solution {
public:
    int memo(int row, int col, vector<vector<int>>&m,vector<vector<int>>&dp){
        if(col < 0 || col > m.size()-1 )return 1e9;
        if(row==m.size()-1)return m[row][col];

        if(dp[row][col] != -10000)return dp[row][col];


        int x = m[row][col] + memo(row+1,col,m,dp);
        int y = m[row][col] + memo(row+1, col-1, m,dp);
        int z = m[row][col] + memo(row+1, col+1, m,dp);

        return dp[row][col] = min({x,y,z});

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-10000));
        for(int i=0;i<matrix.size();i++){
            mini = min(mini,memo(0,i,matrix,dp));
        }
        return mini;

    }
};