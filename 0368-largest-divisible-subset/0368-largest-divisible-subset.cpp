class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>dp(n, 1), hash(n,-1);
        int index = -1;
        int maxi = 0;
        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[i] % nums[prev] == 0 && dp[i] < dp[prev]+1){
                    dp[i] = dp[prev] + 1; 
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                index = i;
            }
        }
        vector<int>res;
        while(index != -1){
            res.push_back(nums[index]);
            index = hash[index];
        }
        return res;
    }
};