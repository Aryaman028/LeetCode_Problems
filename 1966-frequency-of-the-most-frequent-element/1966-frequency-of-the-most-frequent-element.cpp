class Solution {
public:
    // int binarySearch(vector<int>nums,int k,int target,vector<int>pre){
    //     int left =0;
    //     int right = target;
    //     int res=0;
    //     while(left<=right){
    //         int mid = left + (right-left)/2;
    //         int num_count = target-mid+1;
    //         int same_ele_total = nums[target]*num_count;
    //         int ele_sum = pre[target]-pre[mid]+nums[mid];
    //         int op = same_ele_total - ele_sum;
    //         if(k<op){
    //             left=mid+1;
    //         }else{
    //             res = num_count;
    //             right=mid-1;
    //         }
    //     }
    //         return res;
    // }
    int maxFrequency(vector<int>& nums, int k) {
    //     vector<int>pre(nums.size());
    //     int sum=0;
    //     int res=0;
    //     sort(nums.begin(),nums.end());
    //     pre[0]=nums[0];
    //     for(int i=1;i<nums.size();i++){
    //         pre[i]=pre[i-1]+nums[i];
    //     }

    //     for(int i=0;i<nums.size();i++){
    //         res = max(res,binarySearch(nums,k,i,pre));
    //     }
    //     return res;
        
    //Using SLIDING WINDOW
        sort(nums.begin(),nums.end());
        vector<long>pre(nums.size());
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i]=pre[i-1]+nums[i];
        }
        int l=0;
        int r=0;
        int res=0;
        int final=0;
        while(l<=r && r<nums.size()){
            long long target = nums[r];
            int num_count = r-l+1;
            long long window_sum = target*num_count;
            long original_sum = pre[r]-pre[l]+nums[l];
            long ops = window_sum - original_sum;
            if(ops>k){
                l++;
            }else{
                res=max(res,r-l+1);
                r++;
            }
        }
        return res;
    }
};