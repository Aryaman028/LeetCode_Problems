class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Sort items by price
        sort(items.begin(), items.end());
        
        // Precompute the maximum beauty up to each price
        int n = items.size();
        for (int i = 1; i < n; i++) {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }

        // Prepare result array
        vector<int> res(queries.size());

        // For each query, find the maximum beauty using binary search
        for (int i = 0; i < queries.size(); i++) {
            int query = queries[i];
            int start = 0, end = n - 1;
            int max_ele = 0;

            // Binary search to find the highest affordable beauty
            while (start <= end) {
                int mid = start + (end - start) / 2;
                if (items[mid][0] <= query) {
                    max_ele = items[mid][1];  // Update max_ele with max beauty up to this price
                    start = mid + 1;          // Search the right half for potentially higher price
                } else {
                    end = mid - 1;
                }
            }
            res[i] = max_ele;
        }

        return res;
    }
};
