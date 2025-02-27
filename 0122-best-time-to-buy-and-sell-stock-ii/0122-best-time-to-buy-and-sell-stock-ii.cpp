class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        //Just compare the adjacent elements of the prev ele is less than the cur element then we can buy and sell

        // [1,5,7,100] ans => 100-1 = 99
        // 5-1 + 7-5 + 100-7 = 4 + 2 + 93 = 99 which gives the same result

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        
        return profit;        
    }
};