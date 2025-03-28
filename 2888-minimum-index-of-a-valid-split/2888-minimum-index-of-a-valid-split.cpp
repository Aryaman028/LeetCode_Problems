class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i = 0; i < n; i++){
            m[nums[i]]++;
        }
        int maxCount = 0;
        int max_ele = 0;
        for(auto ele: m){
            if(ele.second > maxCount){
                max_ele = ele.first;
                maxCount = ele.second;
            }
        }
        //got the ele with maximum frequency and the max ele also so at every index count the max_ele and check that its greator than the half the size of the 1st array size  and subtracting it from the total frequency then we will get the count of ele in the next half then do the same then compare with the half the size of array
        

        int iniCount = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == max_ele){
                iniCount++;
            }
            int iniLen = i + 1;
            int lastLen = n - iniLen;
            int lastCount = maxCount - iniCount;
            if((iniLen / 2) < iniCount && (lastLen/2) < lastCount){
                return i;
            }
        }
        return -1;
    }
};