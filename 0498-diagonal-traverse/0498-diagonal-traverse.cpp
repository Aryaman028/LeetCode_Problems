class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>v;
        int m= mat.size();  //row
        int n = mat[0].size();  //col
        int row = 0;
        int col=0;
        while(row<m && col<n){
            //down to up
            while(col<n && row>=0 && row<m && col>=0){
                v.push_back(mat[row--][col++]);
            }
            if(col==n){
                row+=2;
                col--;
            }
            else row++;
            //top to down
            while(row<m && col>=0 && row>=0 && col<n){
                v.push_back(mat[row++][col--]);
            }
            if(row==m){
                col+=2;
                row--;
            }
            else col++;
        }
        return v;
    }
};