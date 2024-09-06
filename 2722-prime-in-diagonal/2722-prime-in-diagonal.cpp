class Solution {
public:
    bool isprime(int n){
        if(n<2)return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0)return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int i=0;
        int j=0;
        int res=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((i==j || i+j==n-1) && isprime(nums[i][j])){
                        res=max(res,nums[i][j]);
                }
            }
        }
        if(res<0)return 0;
        return res;
    }
};