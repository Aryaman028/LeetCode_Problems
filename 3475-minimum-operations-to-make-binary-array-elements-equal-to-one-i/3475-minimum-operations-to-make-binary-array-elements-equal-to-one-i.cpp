class Solution {
public:
    int minOperations(vector<int>& nums) {
        //BRUTE FORCE COSTING TC -> O(N * 3);
        //WHENEVER WE WILL BE HAVING ZERO THEN FLIP 3 ELEMENTS

        // int n = nums.size();
        // int c = 0;
        // for(int i = 0; i < n - 2; i++){
        //     if(nums[i] == 0){
        //         for(int j = i; j < i + 3; j++){
        //             nums[j] ^= 1;
        //         }
        //         c++;
        //     }
        // }
        // for(auto ele: nums){
        //     if(ele == 0)return -1;
        // }
        // return c;

        int n = nums.size();
        int c = 0;
        for(int i = 0; i < n - 2; i++){
            if(nums[i] == 0){
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                c++;
            }
        }
        for(auto ele: nums){
            if(ele == 0)return -1;
        }
        return c;
    }
};