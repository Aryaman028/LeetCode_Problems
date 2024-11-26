class Solution {
public:
    void bt(set<vector<int>>&s,int i,vector<int>& nums,vector<int>v){
        if(i==nums.size()){
            s.insert(v);
            return;
        }
        // not take
        bt(s,i+1,nums,v);

        //take
        v.push_back(nums[i]);
        bt(s,i+1,nums,v);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //Using set just to eliminate the duplicates
        set<vector<int>>s;
        sort(nums.begin(),nums.end());
        vector<int>v;
        bt(s,0,nums,v);
        vector<vector<int>>res;
        res.assign(s.begin(),s.end());
        return res;
        
    }
};