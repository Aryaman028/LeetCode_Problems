class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        //FIND THE PREFIX MAX AND THE SUFFIX MAX AND THEN COMPUTE AT EACH INDEX;

        int n = nums.size();
        vector<int>prefixMax(n);
        prefixMax[0] = nums[0];
        int maxRes = 0;
        for(int i = 1 ; i < n; i++){
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }

        vector<int>suffixMax(n);
        suffixMax[n-1] = nums[n-1];
        for(int i = n - 2; i >= 0; i--){
            suffixMax[i] = max(suffixMax[i + 1], nums[i]);
        }

        long long maxi = 0;
        for(int i = 1 ; i < n - 1; i++){
            long long res = (long long)(prefixMax[i - 1] - (long long)nums[i]) * suffixMax[i + 1];
            maxi = max(res,maxi);
        }
        return maxi;
    }
};