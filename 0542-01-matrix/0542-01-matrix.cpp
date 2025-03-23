class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         //YOU WILL BE THINKING TO SOLVE BY TAKING THE 
        // ONES AND APPLY BFS ON EACH ONES INDEX WHICH 
        // WILL CAUSE US O(N^2 * M^2) RATHER THINK OF APPLY BFS ON 
        // ZEROS AND USE A ANY VARIABLE WITH THE CELL INDEX TO STORE
        // THE VAL INTO THE DIST MATRIX WHENEVER THE ELEMENT IS POPING
        
        // STORE ALL THE ZEROS INDEXES IN THE QUEUE AND THEN APPLY MUTLTISOURCE BFS TRAVERSAL
        
        //MULTISOURCE BFS APPLY
        int m = mat.size();
        int n = mat[0].size();

        // {{row,col},val}
        queue<pair<pair<int,int>,int>>q;
        vector<pair<int,int>>directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        vector<vector<bool>>visited(m,vector<bool>(n,false));

        vector<vector<int>>dist(m,vector<int>(n,-1));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    visited[i][j] = true;
                }
            }
        }


        while(!q.empty()){
            int l = q.size();

            while(l--){
                auto [cord, val] = q.front();
                int row = cord.first;
                int col = cord.second;
                q.pop();
                //assigning values
                dist[row][col] = val;

                // moving in all directions
                for(auto [dr, dc] : directions){
                    int newRow = row + dr;
                    int newCol = col + dc;

                    if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n){
                        if(!visited[newRow][newCol]){
                            q.push({{newRow, newCol},val + 1});
                            visited[newRow][newCol] = true;
                        }
                    }
                }
            }
        }

        return dist;
        
    }
};