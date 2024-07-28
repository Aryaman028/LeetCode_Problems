class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        vector<int>v(nums.size(),-1);
        int n = nums.size();
        for(int i=0;i<n*2;i++){
            while(!st.empty() && nums[i%n]>nums[st.top()]){
                v[st.top()]=nums[i%n];
                st.pop();
            }if(i<n)st.push(i);
        }
        return v;
        
    }
};