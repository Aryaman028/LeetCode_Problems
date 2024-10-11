class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int countPosi=0;
        int countNeg=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)countPosi++;
            else if(nums[i]<0)countNeg++;
        }
        return max(countPosi,countNeg);
        
    }
};