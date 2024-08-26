class Solution {
public:
    vector<int> NSE(vector<int>&heights){
        vector<int>v(heights.size(),heights.size());
        stack<int>st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                v[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return v;
    }
    vector<int> PSE(vector<int>&heights){
        vector<int>v(heights.size(),-1);
        stack<int>st;
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>heights[i]){
                v[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return v;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nextsmall=NSE(heights);
        vector<int>prevsmall=PSE(heights);
        int area=INT_MIN;
        for(int i=0;i<heights.size();i++){
            area = max(area,heights[i]*(nextsmall[i]-prevsmall[i]-1));
        }
        return area;
        

    }
};