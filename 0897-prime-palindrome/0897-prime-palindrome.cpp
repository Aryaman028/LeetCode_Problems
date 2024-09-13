class Solution {
public:
    // bool isprime(int n){
    //     if(n<2)return false;
    //     for(int i=2;i<=sqrt(n);i++){
    //         if(n%i==0)return false;
    //     }
    //     return true;
    // }
    bool isprime(int n){
        if(n<2)return false;
        if(n==2) return true;
        if(n%2==0) return false;
        for(int i=3;i*i<=n;i+=2){
            if(n%i==0)return false;
        }
        return true;
    }
    bool ispalindrome(int n){
        int d=0;
        int temp = n;
        while(n>0){ 
            d=d*10 + n%10;
            n/=10;
        }
        if(temp==d)return true;
        return false;

    }
    int primePalindrome(int n) {
        while(true){
            // if(n%2==0)continue;
            if(ispalindrome(n) && isprime(n)){
                return n;
            }
            n++;
        }
        return 0;
    }
};