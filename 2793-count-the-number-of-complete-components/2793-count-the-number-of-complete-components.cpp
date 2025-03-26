class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj, vector<bool>&visited, vector<int>&v){
        visited[node] = true;

        v.push_back(node);

        for(auto ele : adj[node]){
            if(!visited[ele]){
                dfs(ele, adj, visited, v);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        int l = edges.size();
        vector<int>inDegree(n,0);
        vector<vector<int>>adj(n);

        for(int i = 0; i < l; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            inDegree[u]++;
            inDegree[v]++;
        }

        vector<bool>visited(n,false);
        int count = 0;

        //performing DFS on every node and counting the nodes in the component and then using inDegree we know which node have how much indegree thus compare the nodes in a component there indegree should be [n - 1] where n is the number of nodes in that component
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                vector<int>eleInComponent;
                dfs(i,adj,visited,eleInComponent);

                // got the elements into the vector
                int totalNodes = eleInComponent.size();
                bool complete = true;

                //check the indegree of each node present in the current component and mark it complete or not
                for(auto ele : eleInComponent){
                    if(inDegree[ele] != totalNodes - 1){
                        complete = false;
                        break;
                    }
                }
                if(complete){
                    count++;
                }
            }

        }
        return count;
        
    }
};