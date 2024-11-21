class Solution {
public:
    void move(int row,int col,vector<vector<int>>&grid){
        // move above
        for(int i=row-1;i>=0;i--){
            if(grid[i][col]==-1)break;
            grid[i][col]=1;
        }
        // move left
        for(int i=col-1;i>=0;i--){
            if(grid[row][i]==-1)break;
            grid[row][i]=1;
        }
        // move right
        for(int i=col+1;i<grid[0].size();i++){
            if(grid[row][i]==-1)break;
            grid[row][i]=1;
        }
        //move down
        for(int i=row+1;i<grid.size();i++){
            if(grid[i][col]==-1)break;
            grid[i][col]=1;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // -1 means wall and guard
        // 1 means guarded

        vector<vector<int>>grid(m,vector<int>(n,0));

        //marked all the walls in the grid with -1
        for(int i=0;i<walls.size();i++){
            grid[walls[i][0]][walls[i][1]] = -1;
        }
         //marked all the guards in the grid with -1
        for(int i=0;i<guards.size();i++){
            grid[guards[i][0]][guards[i][1]] = -1;
        }

        //moving the guard up down right left
        for(int i=0;i<guards.size();i++){
            int row = guards[i][0];
            int col = guards[i][1];
            move(row,col,grid);
        }
        int count =0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                cout<<grid[i][j]<<" ";
                if(grid[i][j]==0){
                    count++;
                }

            }
            cout<<endl;
        }
        return count;
    }
};