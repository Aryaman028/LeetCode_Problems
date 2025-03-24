class Solution {
public:
    vector<pair<int,int>>dir = {{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(int i, int j, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        grid[i][j] = 0;

        for(auto [dr,dc] : dir){
            int nr = dr + i;    //new row
            int nc = dc + j;

            if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1){
                dfs(nr,nc,grid);
            }
        }
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        //TO ALL THE BOUNDARY ATTACHED NODES DO THE DFS AND MAKE ALL THE NODES 0
        int m = grid.size();
        int n = grid[0].size();
        int countOnes = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || i == m - 1 || j == 0 || j == n - 1){
                    if(grid[i][j] == 1){
                        dfs(i, j, grid);
                    }
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    countOnes++;
                }
            }
        }
        return countOnes;

    }
};