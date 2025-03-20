class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //count total fresh oranges as when we will be converting the fresh to rotten and at the end if the quantity of rotten and fresh is not same then it is not possible to rotten all the oranges

        //also push the indexs of the rotten so that we can begin BFS
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>>q;
        int freshOranges = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }
        cout<<freshOranges<<endl;

        vector<pair<int,int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};

        int time = 0;
        while(!q.empty()){
            int l = q.size();
            bool change = false;
            //we will incrementing time when there is a bfs call and the fresh orange is changed to rotten then only increment
            while(l--){
                pair<int,int>p = q.front();
                int row = p.first;
                int col = p.second;
                q.pop();
                
                // use this method if you want a question for directions
                for(auto [dr,dc] : dir){
                    int newCol = col + dc;
                    int newRow = row + dr;

                    if(newCol >= 0 && newRow >= 0 && newCol < n && newRow < m && grid[newRow][newCol] == 1){
                        grid[newRow][newCol] = 2;
                        change = true;
                        q.push({newRow,newCol});
                        freshOranges--;
                    }
                }

                //basic way to write all the 4 directions

            //     //down
            //     if(row + 1 < m && grid[row + 1][col] == 1){
            //         grid[row + 1][col] = 2;
            //         change = true;
            //         q.push({row + 1,col});
            //         freshOranges--;
            //     }
            //     //up
            //     if(row - 1 >= 0 && grid[row - 1][col] == 1){
            //         grid[row - 1][col] = 2;
            //         change = true;
            //         q.push({row - 1,col});
            //         freshOranges--;
            //     }
            //     //right
            //     if(col + 1 < n && grid[row][col + 1] == 1){
            //         grid[row][col + 1] = 2;
            //         change = true;
            //         q.push({row,col + 1});
            //         freshOranges--;
            //     }
            //     //left
            //     if(col - 1 >= 0 && grid[row][col - 1] == 1){
            //         grid[row][col - 1] = 2;
            //         change = true;
            //         q.push({row,col - 1});
            //         freshOranges--;
            //     }
            }
            if(change == true)time++;

        }

        //freshoranges are zero than there is no oranges left to be rotten thus it is possible to make it now return the time
        if(freshOranges == 0){
            return time;
        }
        return -1;
        
    }
};