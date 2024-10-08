class Solution {
public:
    int check(string s){
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && st.top()=='[' && s[i]==']'){
                st.pop();
            }else st.push(s[i]);
        }
        return st.size();
    }
    int minSwaps(string s) {
        int n = check(s)/2;
        if(n==0)return 0;
        else{
            return (n+1)/2;
        }
        // int count1=0,count2=0,res=0;
        // for(int i=0;i<s.length();i++){
        //     if(s[i]==']'){
        //         count2++;
        //     }else if(s[i]=='['){
        //         count1++;
        //     }
        //     if(count2>count1){
        //         res++;
        //         count2--;
        //         count1++;
        //     }
        // }
        return 0;
    }
};