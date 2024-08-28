class Solution {
public:
    int priority(char a){
        if(a=='*' || a=='/')return 2;
        if(a=='+' || a=='-')return 1;
        return 0;
    }
    int solve(int num1, int num2, char a){
        if(a=='+')return num1+num2;
        else if(a=='-')return num2-num1;
        else if(a=='*')return num2*num1;
        else if(a=='/')return num2/num1;
        return 0;
    }
    
    int calculate(string s) {
        string a ="";
        stack<int>st;
        stack<char>op;
        for(int i=0;i<s.length();i++){
            if(s[i]==' ')continue;
            a+=s[i];
        }
        int n = a.length();
        int i=0;
        while(i<n){
            if(isdigit(a[i])){
                int num=0;
                while(i<n && isdigit(a[i])){
                    num = num*10 + (a[i]-'0');
                    i++;
                }
                st.push(num);
                // continue;
            }
            else{
                while(!op.empty() && priority(op.top())>=priority(a[i])){
                    int num1= st.top();
                    st.pop();
                    int num2=st.top();
                    st.pop();
                    int val = solve(num1,num2,op.top());
                    st.push(val);
                    op.pop();
                }op.push(a[i]);
            i++;
            }
        }

        while(!op.empty()){
            int num1= st.top();
            st.pop();
            int num2=st.top();
            st.pop();
            int val = solve(num1,num2,op.top());
            st.push(val);
            op.pop();
        }
        return st.top();
    }
};