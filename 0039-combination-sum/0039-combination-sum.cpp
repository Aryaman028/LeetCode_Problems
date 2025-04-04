class Solution {
public:
    vector<vector<int>>res;
    void helper(vector<int>& candidates,int i,vector<int>&v, int target){
        if(i>=candidates.size())return;

        if(i==candidates.size()-1){
            if(target==0)res.push_back(v);
        }
        if(target >= candidates[i]){
            v.push_back(candidates[i]);
            helper(candidates,i,v,target-candidates[i]);
            v.pop_back();
        }
        helper(candidates,i+1,v,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>v;
        helper(candidates,0,v,target);
        return res;
    }
};