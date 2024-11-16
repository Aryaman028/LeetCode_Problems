class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //Naive Approach TC-O(n)  SC -> O(n)

        // vector<int>v;
        // int c =0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0){
        //         c++;
        //     }else if(nums[i]!=0){
        //         v.push_back(nums[i]);
        //     }
        // }
        // for(int i=0;i<c;i++){
        //     v.push_back(0);
        // }
        // nums=v;

        
        //TWO POINTER
        int point = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[point],nums[i]);
                point++;
            }
        }
    }


};