class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>v;
        for(int i=0;i<queries.size();i++){
            int res=arr[queries[i][0]];
            for(int j=queries[i][0]+1;j<=queries[i][1];j++){
                res=res^arr[j];
            }
            v.push_back(res);
            
        }
        return v;
    }
};