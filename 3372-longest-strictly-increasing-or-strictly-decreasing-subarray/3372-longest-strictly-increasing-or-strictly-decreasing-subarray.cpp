class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int increasing=0;
        int decreasing=0;
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                decreasing=0;
                increasing++;
            }else if(nums[i-1]>nums[i]){
                increasing=0;
                decreasing++;
            }else{
                increasing =0;
                decreasing =0;
            } 

            ans = max({ans,increasing,decreasing});
        }
        return ans+1;

    }
};