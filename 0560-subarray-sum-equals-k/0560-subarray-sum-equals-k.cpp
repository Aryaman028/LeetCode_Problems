class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //USING PREFIX SUM AND THEN EACH INDEX SUBTRACTING IT FROM K AND CHECKING IF THE RESULT IS PRESENT IN THE MAP OR NOT IF PRESENT THEN ADD THE OCCURENCE OF IT IN TH COUNT
        // [1,2,3] for first test case
        //  1 - 2 = -1;
        //  2 - 2 = 0;     diff 0 will be counted as the subarray can start from the begin also
        //  3 - 2 = 1;     1 exists in the set

        unordered_map<int,int>m;
        vector<int>pre(nums.size());
        pre[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            pre[i] = pre[i - 1] + nums[i];
        }
        int count = 0;
        m[0]++;
        for(int i = 0;i < pre.size(); i++){

            if(m.count(pre[i] - k) > 0){
                count += m[pre[i] - k];
            }
            m[pre[i]]++;
        }
        return count;
    }
};