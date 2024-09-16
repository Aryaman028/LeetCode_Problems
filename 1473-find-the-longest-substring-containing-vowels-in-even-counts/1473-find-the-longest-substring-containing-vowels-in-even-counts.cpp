class Solution {
public:
    int findTheLongestSubstring(string s) {
       unordered_map<string,int>m;
        vector<int>state(5,0);
        string curstate ="00000";
        int res = 0;
        m[curstate]=-1;
        for(int i=0;i<s.length();i++){
            curstate="";
            if(s[i]=='a'){
                state[0]=(state[0] + 1)%2;
            }else if(s[i]=='e'){
                state[1]=(state[1] + 1)%2;
            }else if(s[i]=='i'){
                state[2]=(state[2] + 1)%2;
            }else if(s[i]=='o'){
                state[3]=(state[3] + 1)%2;
            }else if(s[i]=='u'){
                state[4]=(state[4] + 1)%2;
            }
            for(int j=0;j<state.size();j++){
                curstate+=to_string(state[j]);
            }
            if(m.find(curstate)!=m.end()){
                res=max(res,i - m[curstate]);
            }else{
                m[curstate]=i;
            }
        }
        return res;
    }
};