class Solution {
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>>adj(n);

        for(auto arr : roads){
            int u = arr[0], v = arr[1], d = arr[2];
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;


        vector<int>ways(n,0);
        ways[0] = 1;
        vector<long long>dist(n,LLONG_MAX);
        

        pq.push({0,0});
        dist[0] = 0;

        while(!pq.empty()){
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (d > dist[node]) continue;

            for(auto ele : adj[node]){
                int adjnode = ele.first;
                int wt = ele.second;

                long long res = (long long)wt + d;

                if(res < dist[adjnode]){
                    dist[adjnode] = res;
                    ways[adjnode] = ways[node];
                    pq.push({res, adjnode});
                }else if(res == dist[adjnode]){
                    ways[adjnode] = (ways[adjnode] + ways[node])% mod;
                }
            }
        }
        return ways[n-1];
       

    }
};