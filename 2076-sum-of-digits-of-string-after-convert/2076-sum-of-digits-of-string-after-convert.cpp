class Solution {
public:
    int getLucky(string s, int k) {
        int n=s.length();
        vector<int>v;
        string num = "";
        for(int i=0;i<n;i++){
            int val = s[i]- 96;
            num +=  to_string(val);
        }
        int sum=0;
        for(int i=0;i<num.length();i++){
            int val =num[i]-'0';
            sum+=val;
        }
        while(--k){
            int d=0;
            while(sum>0){
                d+=sum%10;
                sum/=10;
            }
            if(d<10)return d;
            sum=d;
        }
        
       return sum;
    }
};