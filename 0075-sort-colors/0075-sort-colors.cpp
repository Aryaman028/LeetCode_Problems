class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());        //O(nlogn)
        //using 3 pointer                     //O(n)
        //using count of all 0,1,2            //O(n)

        int n=nums.size();
        int left = 0;
        int right = n-1;
        int mid = 0;
        while(mid<=right){
            if(nums[mid]==0){
                swap(nums[mid],nums[left]);
                left++;
                mid++;
            }else if(nums[mid]==1){
                mid++;
            }else if(nums[mid]==2){
                swap(nums[mid],nums[right]);
                right--;
            }
        }
        

    }
};