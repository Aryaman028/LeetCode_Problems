class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l = nums.size();
        int sum=0;
        int res=0;
        int maxi=INT_MIN;
        for(int i =0;i<l;i++){
            sum+=nums[i];
            if(sum<0)sum=0;
            res=max(res,sum);
        }
        int max_ele=INT_MIN;
        if(res==0){
            for(int i=0;i<l;i++){
                max_ele=max(max_ele,nums[i]);
            }
            return max_ele;
        }
        return res;
    }
};