class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>res1;
        s1 += " " + s2;
        stringstream ab(s1);
        map<string,int>m;
        vector<string>fin;
        string temp;
        while(ab>>temp){
                m[temp]++;
        }
        for(auto ele:m){
            if(ele.second==1){
                fin.push_back(ele.first);
            }
        }
        return fin;
        
    }
};