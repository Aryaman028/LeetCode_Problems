class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>m;

        for(auto it: s){
            m[it]++;
        }

        for(auto it: t){
            m[it]--;
        }

        for(auto it:m){
            if(it.second!=0){
                return it.first;
            }
        }
        return ' ';
    }
};