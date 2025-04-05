class Solution {
public:
    vector<pair<int,int>>directions = {{1,0}, {0,1}, {-1,0}, {0,-1}, {-1,-1}, {1,1}, {-1,1}, {1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        //There is no need of using priority queue as the weights of the edges are unit dist thus all the dist in the PQ will be same, We need PQ when we need the shortest dist among the stored dist inside queue
        
        if(grid[0][0] == 1)return -1;
        // priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;

        queue<pair<int,pair<int,int>>>pq;

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dist(m, vector<int>(n, 1e9));

        // {dist, {row,col}}

        pq.push({0, {0,0}});
        dist[0][0] = 1;
        
        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    dist[i][j] = -1;
                }
            }
        }

        while(!pq.empty()){
            int d = pq.front().first;
            int row = pq.front().second.first;
            int col = pq.front().second.second;
            pq.pop();

            for(auto [dr, dc] : directions){
                int newrow = row + dr;
                int newcol = col + dc;
                
                if(newrow >= 0 && newcol >= 0 && newrow < m && newcol < n && dist[newrow][newcol] != -1){
                    if(dist[row][col] + 1 < dist[newrow][newcol]){
                        dist[newrow][newcol] = dist[row][col] + 1;
                        pq.push({dist[row][col] + 1, {newrow, newcol}});
                    }
                }
            }
        }

        //  for(int i = 0 ; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         cout<<dist[i][j]<<" ";
        //     }cout<<endl;
        // }
        if(dist[m - 1][n - 1]==1e9)return -1;
        return dist[m - 1][n - 1];
    }
};