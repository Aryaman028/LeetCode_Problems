class Solution {
public:

    void helper(vector<int>&nums, int ind, vector<int>&v,vector<vector<int>>&res){
       
        res.push_back(v);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1])continue;
            v.push_back(nums[i]);
            helper(nums,i+1,v,res);
            v.pop_back();
        }
      
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // OPTIMAL APPROCAH
        vector<int>v;
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        helper(nums,0,v,res);
        return res;
    }
};