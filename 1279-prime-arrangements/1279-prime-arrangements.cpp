class Solution {
public:
    unsigned long long d = pow(10,9)+7;

    unsigned long long factorial(int n){
        if(n==1)return 1;
        return n*factorial(n-1)%d;   //using this module here as on multipling it gets overflow

    }
    //SIEVE OF ERATOSTHENES [optimal way to find prime number]
    void seive(vector<int>&prime,int n){
        prime[0]=prime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=false;
                }
            }
        }
    }
    int numPrimeArrangements(int n) {
        if(n<=2)return 1;
        vector<int>prime(n+1,true);
        seive(prime,n);
        int c=0;
        for(int i=2;i<=n;i++){
            if(prime[i])c++;
        }
        unsigned long long a = factorial(c);
        unsigned long long b = factorial(n-c);
        return a*b%d;
    }
};