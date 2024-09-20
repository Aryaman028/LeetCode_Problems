class Solution {
public:
    bool happy(int n,long sum){
        if(n==1 || n==7){
            return true;
        }
        if(n>1 && n<=9)return false;
        int temp=n;
        while(temp>0){
            int d=temp%10;
            sum+=d*d;
            temp/=10;
        }
        return happy(sum,0);
    }

    bool isHappy(int n) {
        // int sum=0;
        // bool flag =true;
        // while(n>0){
        //     int d = n%10;
        //     sum+=pow(d,2);
        //     n/=10;
        //     if(n==0){
        //         if(sum==1 || sum==7){
        //             return true;
        //         }
        //         if(sum>=1 && sum<=9){
        //             return false;
        //         }
        //         n=sum;
        //         sum=0;
        //     }
        // }return flag;
        return happy(n,0);
    }
};