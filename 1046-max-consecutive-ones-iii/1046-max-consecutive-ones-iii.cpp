class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, ans = 0;

        int n = nums.size();

        while(r < n){
            while(nums[r] == 0 && k == 0){
                // then we will shrink till one zero from the left gets eliminate
                if(nums[l] == 0){
                    k++;
                }
                l++;
            }

            if(nums[r] == 0) k--;

            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};