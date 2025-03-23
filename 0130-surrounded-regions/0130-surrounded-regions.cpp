class Solution {
public:
    vector<pair<int,int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int row, int col,vector<vector<bool>>&visited, vector<vector<char>>& board, vector<vector<char>>&dist){

        int m = board.size();
        int n = board[0].size();
        visited[row][col] = true;
        dist[row][col] = 'O';
        for(auto [dr, dc] : dir){
            int newRow = row + dr;
            int newCol = col + dc;

            if(newRow >= 0 && newCol >= 0 && newRow < m && newCol < n){
                if(!visited[newRow][newCol] && board[newRow][newCol] == 'O'){
                    dfs(newRow, newCol,visited,board,dist);
                }
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        //traverse the board  and whenever there is a O at the boundary then do the DFS and mark O to all the cells DFS is going

        int m = board.size();
        int n = board[0].size();
        vector<vector<char>>dist(m,vector<char>(n,'X'));
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        //for row
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O' && !visited[i][0]){
                dfs(i,0,visited,board,dist);
            }
            if(board[i][n-1] == 'O' && !visited[i][n-1]){
                dfs(i,n-1,visited,board,dist);
            }
        }
        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O' && !visited[0][i]){
                dfs(0,i,visited,board,dist);
            }
            if(board[m-1][i] == 'O' && !visited[m-1][i]){
                dfs(m - 1,i,visited,board,dist);
            }
        }

        board = dist;

        
    }
};