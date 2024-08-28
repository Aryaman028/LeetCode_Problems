class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //brute force giving TLE
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         ans = max(ans,prices[j]-prices[i]);
        //     }
        // }
        // return ans;
        int n = prices.size();
        int maxprofit=0;
        int minval=INT_MAX;
        for(int i=0;i<n;i++){
            if(minval>prices[i]){
                minval = prices[i];
            }
            int profit = prices[i]-minval;
            if(profit>maxprofit){
                maxprofit=profit;
            }
        }
        return maxprofit;







        // int minans = INT_MAX;
        // int maxans = 0;
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     maxans=max(maxans,prices[n-1]);
        //     minans=min(minans,prices[0]);
        //     if(i>0 && i<n-1 && prices[i-1]>prices[i] && prices[i]<prices[i+1]){
        //         minans=min(minans,prices[i]);
        //         // cout<<minans<<" ";
        //     }else if(i>0 && i<n-1 && prices[i-1]<prices[i] && prices[i]>prices[i+1]){
        //         maxans=max(maxans,prices[i]);
        //         // cout<<maxans<<" ";
        //     }
        //     ans = max(ans,maxans-minans);
        //     cout<<ans<<" ";
        // }
        // // int ans = maxans-minans;
        // if(ans>0)return ans;
        // else return 0;
    }
};