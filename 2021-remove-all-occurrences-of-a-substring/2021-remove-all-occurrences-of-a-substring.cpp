class Solution {
public:
    string removeOccurrences(string s, string part) {
        int i=0;
        int n= part.size();
        while(i<s.length()){
            int j=0;
            while(j<part.length() && s[i+j]==part[j]){
                j++;
            }
            if(j==n){
                s.erase(i,n);
                if(i>=n-1)i-=n-1;
                else i=0;
            }else i++;
        }
        return s;
    }
};