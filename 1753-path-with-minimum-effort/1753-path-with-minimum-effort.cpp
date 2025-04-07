class Solution {
public:
    vector<pair<int,int>>directions = {{1,0}, {-1,0}, {0,-1}, {0,1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;


        vector<vector<int>>dist(m, vector<int>(n,1e9));


        // {dist, {row,col}};
        pq.push({0, {0,0}});
        dist[0][0] = 0;

        while(!pq.empty()){
            int d = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop();

            for(auto [dr,dc] : directions){
                int newrow = row + dr;
                int newcol = col + dc;

                if(newrow >= 0 && newrow < m && newcol >= 0 && newcol < n){
                    int edgeWt = abs(heights[row][col] - heights[newrow][newcol]);
                    int neweffort = max(edgeWt,d);

                    if(neweffort < dist[newrow][newcol]){
                        pq.push({neweffort, {newrow, newcol}});
                        dist[newrow][newcol] = neweffort;
                    }
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};