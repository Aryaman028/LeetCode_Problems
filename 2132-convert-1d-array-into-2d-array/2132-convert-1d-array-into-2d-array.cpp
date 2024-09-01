class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>res;
        int c=0;
        vector<int>v;
        // if(original.size()<3)return res;
        if(n*m != original.size())return res;
        for(int i=0;i<original.size();i++){
            if(c<n){
                v.push_back(original[i]);
                c++;
            }
            if(c==n){
                res.push_back(v);
                c=0;
                v.erase(v.begin(),v.end());
            }
        }
        return res;
    }
};