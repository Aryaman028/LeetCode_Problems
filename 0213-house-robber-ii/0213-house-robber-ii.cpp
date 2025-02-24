class Solution {
public:
    int helper(vector<int>&nums, int i, vector<int>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];

        //this condition is added to check the first and the last ele
        
        //pick
        int x=nums[i] + helper(nums,i+2,dp);
        //not pick
        int y = helper(nums,i+1,dp);

        return dp[i] = max(x,y);
    }


    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp1(n-1,-1);
        vector<int>dp2(n-1,-1);

        if(n==1)return nums[0];

        vector<int>temp1;
        vector<int>temp2;

        for(int i=1;i<n;i++){
            temp1.push_back(nums[i]);
        }
        for(int i=0;i<n-1;i++){
            temp2.push_back(nums[i]);
        }

        int leaving_first =  helper(temp1,0,dp1);
        // dp={-1};
        int leaving_last = helper(temp2,0,dp2);

        return max(leaving_first,leaving_last);
    }
};