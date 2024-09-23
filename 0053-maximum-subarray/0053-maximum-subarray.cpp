class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l = nums.size();
        int sum=nums[0];
        int res=nums[0];
        for(int i =1;i<l;i++){
            // sum+=nums[i];
            // if(sum<0)sum=0;            //whenever our sum becomes less than 0 get it 0;
            sum=max(sum+nums[i],nums[i]);
            res=max(res,sum);
        }
        // int max_ele=INT_MIN;

        // //when there are all negative elements then our res will be zero 
        // // but we have to give the max element in the nums so calculating it.
        // if(res==0){                    
        //     for(int i=0;i<l;i++){
        //         max_ele=max(max_ele,nums[i]);
        //     }
        //     return max_ele;
        // }
        return res;
    }
};