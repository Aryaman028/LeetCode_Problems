class Solution {
public:
    void move(int row, int col,vector<vector<char>>& res){
        int n = res.size();
        for(int i = row; i < n; i++){
            if(res[i][col] == '.'){
                swap(res[i][col], res[row][col]);
            }
            if(res[i][col] == '*'){
                break;
            }
        }
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>>res(m,vector<char>(n,'.'));

        //forming a new mattrix
        for(int i = 0; i < m; i++){
            for(int j = 0; j< n; j++){
                res[i][j] = boxGrid[j][i];
            }
            //reversing the row
            reverse(res[i].begin(),res[i].end());
        }

        //move the current # to the down the column where is free space
        for(int i = 0; i < m; i++){
            for(int j = 0; j< n; j++){
                if(res[i][j] == '#'){
                    move(i,j,res);
                }
            }
        }
        return res;
    }
};