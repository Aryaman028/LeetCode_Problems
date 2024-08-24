class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>suf(n);
        vector<int>pre(n);
        vector<int>res(n);
        int p=1;
        for(int i=0;i<n;i++){
            p*=nums[i];
            pre[i]=p;
        }
        p=1;
        for(int i=n-1;i>=0;i--){
            p*=nums[i];
            suf[i]=p;
        }
        for(int i=0;i<n;i++){
            if(i==0){
                res[i]=suf[i+1];
            }else if(i==n-1){
                res[i]=pre[i-1];
            }else{
                res[i]=pre[i-1]*suf[i+1];
            }
        }
        return res;
    }
};