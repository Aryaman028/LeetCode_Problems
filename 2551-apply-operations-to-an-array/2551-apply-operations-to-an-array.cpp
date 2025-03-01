class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n - 1; i++){
            if(nums[i] == nums[i + 1]){
                nums[i]  = nums[i] * 2;
                nums[i+1] = 0;
            }
        }
        int zeroPosi=-1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                if(zeroPosi == -1) zeroPosi = i;
            } 
            else{
                if(zeroPosi != -1){
                    swap(nums[zeroPosi],nums[i]);
                    zeroPosi++;
                }
            }
        }
        // int j=0;

        // for(int i = 0;i < n; i++){
        //     if(nums[i] != 0)res[j++] = nums[i] ;

        // }
        return nums;
        
    }
};