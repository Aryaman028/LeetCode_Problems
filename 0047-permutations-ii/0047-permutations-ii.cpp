class Solution {
public:
    void helper(vector<int>&nums,int i,vector<vector<int>>&res){
        if(i==nums.size()){
            res.push_back(nums);
            return;
        }
        unordered_set<int>s;
        for(int j=i;j<nums.size();j++){
            //Just this condition is added to remove the duplicates and all the solution is same just as for permutation 1 

            //we have not used the if condition where we compare the adjasent element is equal then continue as that condition is useful in subset only as here swaping is done due to which adjasent element get change.
            // if(j > i && nums[j-1] == nums[j])continue;
            if(s.count(nums[j]))continue;
            s.insert(nums[j]);

            swap(nums[i],nums[j]);
            helper(nums,i+1,res);
            //To prevent it from changing the original array  BACKTRACKING
            swap(nums[i],nums[j]);

        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        helper(nums,0,res);
        return res;

    }
};