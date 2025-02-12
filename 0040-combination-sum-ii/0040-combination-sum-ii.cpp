class Solution {
public:
    void helper(vector<int>&c,int ind, int target,vector<int>&v, vector<vector<int>>&res){

        if(target==0){
            res.push_back(v);
            return;
        }
        for(int i=ind;i<c.size();i++){
            if(i>ind && c[i]==c[i-1])continue;
            if(target<c[i])break;
            v.push_back(c[i]);
            helper(c,i+1,target-c[i],v,res);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<vector<int>>res;
        vector<int>v;
        sort(c.begin(),c.end());
        helper(c,0,target,v,res);
        return res;
    }
};