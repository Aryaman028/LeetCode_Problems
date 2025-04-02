class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi = -1;
        int n = nums.size();
        for(int i = 0; i < n-2; i++){
            for(int j = i + 1; j < n-1; j++){
                for(int k = j + 1; k < n; k++){
                    maxi = max(maxi, (long long) (nums[i] - nums[j]) * nums[k]);
                }
            }
        }
        if(maxi == -1){
            return 0;
        }
        return maxi;
    }
};