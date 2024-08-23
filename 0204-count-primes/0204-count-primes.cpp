class Solution {
public:
    void seive(vector<int>& prime, int n){
        prime[0] = prime[1] = false;
        for(int i=2 ; i*i<=n ; i++){
            if(prime[i]){
                for(int j=i*i; j<=n; j+=i){
                    prime[j]=false;
                }
            }
        }
    }
    int countPrimes(int n) {
        if(n<=2)return 0;
        vector<int>prime(n,true);
        seive(prime,n-1);
        int c=0;
        for(int i=2;i<n;i++){
            if(prime[i])c++;
        }
        return c;
    }
};