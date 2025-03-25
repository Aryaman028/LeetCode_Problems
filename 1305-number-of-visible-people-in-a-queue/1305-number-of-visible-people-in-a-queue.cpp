class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] > heights[st.top()]) {
                res[st.top()]++;
                st.pop();
            }
            //khali nhi hua stack mtlb ki st.top() badha abhi tak nhi aaya
            if (!st.empty()) {
                res[st.top()]++;
            }
            st.push(i);
        }
        return res;
    }
};
