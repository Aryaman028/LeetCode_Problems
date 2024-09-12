class Solution {
public:
    bool check(vector<int>& nums) {
        //its time complixety will be O(nlogn)

        // vector<int>res;
        // int k=0;
        // bool flag =false;
        // for(int i=1;i<nums.size();i++){
        //     if(nums[i-1]>nums[i]){
        //         k=i-1;              //position of the peak element
        //         flag=true;         //it is getting a peak element
        //     }
        // }
        // if(k==0 && !flag)k=nums.size()-1;       //that the array is already sorted

        // //storing the elements in different array
        // for(int i=k+1;i<nums.size();i++){
        //     res.push_back(nums[i]);
        // }
        // for(int i=0;i<=k;i++){
        //     res.push_back(nums[i]);
        // }
        // sort(nums.begin(),nums.end());
        // if(k==nums.size())return true;
        // if(res==nums)return true;
        // return false;

        //2nd APPROACH
        int c=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                c++;
            }
        }
        if(c==0)return true;
        else if(c==1 && nums[0]>=nums[nums.size()-1])return true;
        else return false;

        return false;



    }
};