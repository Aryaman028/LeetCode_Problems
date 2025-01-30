class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_ele=INT_MAX;
        int max_profit =0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min_ele){
                min_ele = prices[i];
            }
            if(prices[i]>min_ele){
                max_profit = max(max_profit,prices[i]-min_ele);
            }
        }
        return max_profit;
    }
};