class Solution {
public:
    int minLength(string s) {
        int i=0;
        while(i<s.length()){
            if(s.substr(i,2)=="AB" || s.substr(i,2)=="CD"){
                s.erase(i,2);
                cout<<s<<" ";
                if(i==0)i=0;
                else i-=1;
                continue;
            }
            i++;
        }
        return s.length();   
    }
};