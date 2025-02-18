class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                m[edges[i][j]]++;
            }
        }
        
        for(auto ele: m){
            if(ele.second==n){
                return ele.first;
            }
        }
        return -1;
    }
};