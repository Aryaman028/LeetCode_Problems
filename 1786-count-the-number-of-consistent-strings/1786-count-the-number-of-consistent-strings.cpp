class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char>s;
        for(int i=0;i<allowed.length();i++){
            s.insert(allowed[i]);
        }
        int c=0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                if(s.find(words[i][j])==s.end()){
                    c++;
                    break;
                }
            }
        }   
        return words.size()-c;     
    }
};