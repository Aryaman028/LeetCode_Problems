class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        for(int i = 0; i < n - 2; i++){
            if(nums[i] == 0){
                for(int j = i; j < i + 3; j++){
                    nums[j] ^= 1;
                }
                c++;
            }
        }
        for(auto ele: nums){
            if(ele == 0)return -1;
        }
        return c;
    }
};