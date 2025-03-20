class Solution {
public:

    void dfs(int node, vector<bool>&visited, vector<vector<int>>&adj){
        if(visited[node] == true)return;

        visited[node] = true;

        for(auto ele : adj[node]){
            dfs(ele,visited,adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        //using adjascency list
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        //apply dfs and count how many times dfs will be called
        vector<bool>visited(n,false);
        int c = 0;
        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                dfs(i, visited, adj);
                c++;
            }
        }
        return c;        
    }
};