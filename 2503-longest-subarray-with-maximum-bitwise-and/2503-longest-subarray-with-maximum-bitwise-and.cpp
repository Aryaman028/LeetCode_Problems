class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_value = INT_MIN;
        int max_index = 0;
        //getting the max value and the index of it
        for(int i=0;i<nums.size();i++){
            if(max_value<nums[i]){
                max_value = nums[i];
                max_index = i;
            }
        }
        int n = nums.size();
        int c=0;
        int length = 0;

        //starting from the index of max and counting the max 
        //Edge case - [1,2,3,4,4,2,3,4,4,4,4]  then it 
        // will count 4 two times only
        while(max_index<n){
            if(nums[max_index]==max_value){
                c++;
                length=max(length,c);
            }else{
                c=0;
            }
            max_index++;
        }
        return length;
    }
};