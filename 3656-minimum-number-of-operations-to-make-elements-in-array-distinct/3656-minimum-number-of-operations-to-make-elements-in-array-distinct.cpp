class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>m;
        int  i = nums.size() - 1;
        int operations = 0;
        while(i >= 0){
            m[nums[i]]++;

            if(m[nums[i]] > 1){
                while(i >= 0){
                    i = i - 3;
                    operations++;
                }
            }else i--;
        }
        return operations;
    }
};