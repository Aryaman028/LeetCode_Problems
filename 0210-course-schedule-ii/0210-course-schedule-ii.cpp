class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //we can do it using kahns Algorithm in which we use BFS in a ACYCLIC DIRECTED GRAPH and print the array in such a way that u -> v then 'u' comes before 'v'

        int n = numCourses;
        vector<vector<int>>adj(n);
        
        vector<int>inDegree(n);

        for(int i = 0; i < prerequisites.size() ; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            // u <- v
            inDegree[u]++;
            adj[v].push_back(u);
        }
        
        queue<int>q;
        //pushing all the nodes having inDegree 0;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        //then performing BFS and decrementing the indegree of its neighbours and if its indegree gets 0 then push it to the queue 
        
        vector<int>res;
        while(!q.empty()){
            int l = q.size();

            while(l--){
                int node = q.front();
                res.push_back(node);
                q.pop();
                for(auto ele : adj[node]){
                    inDegree[ele]--;
                    if(inDegree[ele]==0){
                        q.push(ele);
                    }
                }
            }
        }
        //if it has traveled whole nodes then it is ACYCLIC DIRECTED GRAPH thus return the vector
        if(res.size() == n){
            return res;
        }
        //if not then there is a cycle due to which it is imposible to travel whole node
        return {};

    }
};
