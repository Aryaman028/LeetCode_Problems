class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0, r = 0, maxi = 0;
        int n  = nums.size();
        unordered_map<int,int>m;
        while(r < n){
            m[nums[r]]++;
            while(m[nums[r]] > k){
                m[nums[l]]--;
                l++;
            }

            int len = r - l + 1;
            maxi = max(maxi,len);
            r++;
        }
        return maxi;
    }
};