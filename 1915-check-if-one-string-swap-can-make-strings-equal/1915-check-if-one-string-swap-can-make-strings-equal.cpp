class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)return true;
        for(int i=0;i<s1.length();i++){
            if(s1[i]==s2[i])continue;
            for(int j=i+1;j<s1.length();j++){
                swap(s1[i],s1[j]);
                if(s1==s2)return true;
                swap(s1[i],s1[j]);
            }
        }
        return false;
    }
};