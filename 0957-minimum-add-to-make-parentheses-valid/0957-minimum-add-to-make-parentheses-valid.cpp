class Solution {
public:
    // int check(string s){
    //     stack<char>st;
    //     for(int i=0;i<s.length();i++){
    //         if(!st.empty() && st.top()=='(' && s[i]==')'){
    //             st.pop();
    //         }else st.push(s[i]);
    //     }
    //     return st.size();
    // }
    int minAddToMakeValid(string s) {

        //APPROACH USES STACK WHICH WILL CAUSE TC->O(N)  SC->O(N)

        // int n = check(s);
        // return n;

        //OPTIMAL APPROACH USING COUNTERS FOR OPEN AND CLOSE
        //  TC->O(N) SC->O(1);
        int open=0;
        int close=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                open++;
            }else if(s[i]==')' && open>0){
                open--;
            }else close++;
        }
        return open+close;
    }



};