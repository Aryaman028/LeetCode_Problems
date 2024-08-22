class Solution {
public:
    int findComplement(int num) {
        int n=num;
        int c=0;
        while(n>0){
            n/=2;
            c++;
        }
        int f = pow(2,c)-1;
        int res = num ^ f;
        return res;
    }
};