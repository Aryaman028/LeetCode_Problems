class Solution {
public:
    long long helper(int i , vector<vector<int>>& q, vector<long long>&dp){
        if(i >= q.size())return 0;

        if(dp[i] != -1)return dp[i];

        long long pick = q[i][0] + helper(i + q[i][1] + 1, q, dp);
        long long notPick = helper(i + 1, q, dp);

        return dp[i] = max(pick,notPick);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n, -1);
        return helper(0, questions, dp);
    }
};