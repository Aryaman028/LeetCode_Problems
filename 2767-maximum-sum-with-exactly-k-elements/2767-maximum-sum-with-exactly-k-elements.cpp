class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int max_sum = 0;
        int max_ele = 0;
        for(auto ele:nums){
            max_ele = max(max_ele,ele);
        }
        for(int i=0;i<k;i++){
            max_sum += max_ele;
            max_ele++;
        }
        return max_sum;
    }
};