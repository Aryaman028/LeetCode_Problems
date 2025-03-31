class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int>pairSum;

        //Done in the diary IMP questions;


        for(int i = 0; i < weights.size() - 1; i++){
            pairSum.push_back(weights[i] + weights[i+1]);
        }
        int n = pairSum.size();

        sort(pairSum.begin(), pairSum.end());

        int total = 0;
        long long maxSum =0;
        long long minSum =0;
        for(int i = 0 ; i < k - 1; i++){
            minSum += pairSum[i];
            maxSum += pairSum[n - i - 1];
        }
        return maxSum - minSum;
        
        
    }
};