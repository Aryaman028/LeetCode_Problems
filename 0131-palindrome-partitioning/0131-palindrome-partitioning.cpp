class Solution {
public:
    bool palindrome(int i, int j, string s){
        while( i <= j){
            if(s[i++] != s[j--])return false;
        }
        return true;
    }
    void helper(int i, string s,vector<string>&v, vector<vector<string>>&res){
        if(i==s.length()){
            res.push_back(v);
            return;
        }

        for(int j = i; j <s.length(); j++){
            if(palindrome(i,j,s)){
                string sub = s.substr(i,j - i + 1);
                v.push_back(sub);
                //take care of this case we have to now find from the next index of j
                helper(j+1,s,v,res);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>v;
        helper(0,s,v,res);
        return res;
    }
};