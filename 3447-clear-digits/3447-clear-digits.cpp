class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && st.top()>='a' && st.top()<='z' && s[i]>='0' && s[i]<='9'){
                st.pop();
            }else st.push(s[i]); 
        }
        string a="";
        while(!st.empty()){
            a = st.top() + a;
            st.pop();
        }
        return a;
    }
};