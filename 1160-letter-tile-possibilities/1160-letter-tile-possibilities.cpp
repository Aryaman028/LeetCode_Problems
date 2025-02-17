class Solution {
public:
    void subsequence(int ind,string a,string tiles,vector<string>&v){
        // if(ind==tiles.size()){
        //     v.push_back(a);
        //     return;
        // }
        v.push_back(a);
        for(int i=ind;i<tiles.size();i++){
            if(i>ind && tiles[i]==tiles[i-1])continue;
            subsequence(i+1,a+tiles[i],tiles,v);
        }
    }
    int fact(int n){
        int pro=1;
        for(int i=1;i<=n;i++){
            pro*=i;
        }
        return pro;
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        vector<string>v;
        subsequence(0,"",tiles,v);

        int result = 0;
        for(string ele:v){
            unordered_map<char,int>m;
            int deno=1;
            for(auto ch : ele){
                m[ch]++;
            }

            for(auto ch : m){
                if(ch.second>1){
                    deno*=fact(ch.second);  
                }
            }
            result += fact(ele.length()) / deno;
        }
        return result-1;
    }
};