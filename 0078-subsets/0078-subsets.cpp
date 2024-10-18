class Solution {
public:
    vector<vector<int>>v;
    void bt(vector<int>nums,int i,vector<int>part){
        if(i==nums.size()){
            v.push_back(part);
            return;
        }
        //not take
        bt(nums,i+1,part);

        //take
        part.push_back(nums[i]);
        bt(nums,i+1,part);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>part;
        bt(nums,0,part);
        return v;
    }
};