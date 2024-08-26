class Solution {
public:
    string finalString(string s) {
        string a = "";
        for(int i=0;i<s.length();i++){
            if(s[i]=='i'){
                reverse(a.begin(),a.end());
            }else{
                a+=s[i];
            }
        }return a;
    }
};