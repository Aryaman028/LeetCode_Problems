class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>v(26);

        for(auto it: s){
            v[it-'a']++;
        }

        for(auto it: t){
            v[it-'a']--;
        }

        for(int i=0;i<26;i++){
           if(v[i]==-1)return (char) i +'a';
        }
        return ' ';
    }
};