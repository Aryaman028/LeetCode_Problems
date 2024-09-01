class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        if(n*m != r*c)return mat;
        int k=0;
        vector<vector<int>>res;
        vector<int>v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(k<c){
                    v.push_back(mat[i][j]);
                    k++;
                }
                if(k==c){
                    res.push_back(v);
                    k=0;
                    v.clear();
                }
            }
        }
        return res;
        
    }
};