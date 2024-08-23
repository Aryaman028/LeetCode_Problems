class Solution {
public:
    void isprime(vector<int>&prime,int n){
        prime[0]=prime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*i;j<=n;j+=i){  //we are finding the multiple of the number
                    prime[j]=false;
                }
            }
        } 
    } 
    vector<vector<int>> findPrimePairs(int n) {
        vector<int>prime(n+1,true);
        isprime(prime,n);
        vector<vector<int>>res;
        for(int i=2;i<=n/2;i++){
            int j = n-i;
            if(prime[i] && prime[j]){
                vector<int>v;
                v.push_back(i);
                v.push_back(j);
                res.push_back(v);
            }
        }
        return res;
    }
};