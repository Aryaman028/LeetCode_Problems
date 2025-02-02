class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int>v=nums;
        sort(v.begin(),v.end());
        int index =-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                index=i;
                break;
            }
        }
        if(index==-1)return true;
        for(int i=0;i<nums.size();i++){
            if(nums[(i+index) % nums.size()]!=v[i]){
                return false;
            }
        }
        return true;

    }
};