class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_value = INT_MIN;
        int max_index = 0;
        for(int i=0;i<nums.size();i++){
            if(max_value<nums[i]){
                max_value = nums[i];
                max_index = i;
            }
        }
        cout<<max_value<<" ";
        cout<<max_index<<" ";
        int n = nums.size();
        int c=0;
        vector<int>v;
        while(max_index<n){
            if(nums[max_index]==max_value){
                c++;
            }else if(nums[max_index]!=max_value){
                v.push_back(c);
                c=0;
            }
            max_index++;
        }
        v.push_back(c);
        int m=v[0];
        for(int i=0;i<v.size();i++){
            m=max(m,v[i]);
        }
        return m;
    }
};