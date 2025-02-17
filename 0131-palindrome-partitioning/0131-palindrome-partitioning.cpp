class Solution {
public:
    bool palindrome(int start, int end,string s){
        while(start<end){
            if(s[start++]!=s[end--])return false;
        }
        return true;
    }
    void helper(string s,int ind,vector<vector<string>>&res ,vector<string>&v){
        if(ind==s.length()){
            res.push_back(v);
            return;
        }

        for(int i=ind;i<s.length();i++){
            if(palindrome(ind,i,s)){
                v.push_back(s.substr(ind,i - ind + 1));
                helper(s,i+1,res,v);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>v;

        helper(s,0,res,v);
        return res;
    }
};