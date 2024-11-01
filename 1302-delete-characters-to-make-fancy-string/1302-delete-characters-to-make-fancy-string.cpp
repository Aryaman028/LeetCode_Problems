class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        int i=1;
        int occur=1;
        char val =s[0];
        res+=s[0];
        while(i<s.length()){
            if(val==s[i]){
                occur++;
            }else{
                val = s[i];
                occur=1;
            } 
            if(occur<3){
                res+=s[i];
            }
            i++;
        }
        return res;
    }
};