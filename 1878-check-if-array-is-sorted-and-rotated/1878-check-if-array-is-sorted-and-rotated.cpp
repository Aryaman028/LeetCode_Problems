class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int>res;
        int k=0;
        bool flag =false;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                k=i-1;
                flag=true;
            }
        }
        cout<<k<<endl;
        if(k==0 && !flag)k=nums.size()-1;
        for(int i=k+1;i<nums.size();i++){
            res.push_back(nums[i]);
        }
        for(int i=0;i<=k;i++){
            res.push_back(nums[i]);
        }
        sort(nums.begin(),nums.end());
        if(k==nums.size())return true;
        for(int a:res){
            cout<<a<<" ";
        }
        if(res==nums)return true;
        return false;
        // reverse(nums.begin()+k+1,nums.end());
        // reverse(nums.begin(),nums.begin()+k);
        // reverse(nums.begin(),nums.end());
    }
};