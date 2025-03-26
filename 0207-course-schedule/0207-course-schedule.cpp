class Solution {
public:
    bool detect(int node, vector<bool>&visited, vector<bool>&curPath,vector<vector<int>>&adj  ){
        //cycle detect
        visited[node] = true;
        curPath[node] = true;

        for(auto ele:adj[node]){
            if(!visited[ele]){
                if(detect(ele,visited,curPath,adj))return true;

                //if ele is visited and also true in the curpath then it is a cycle
            }else if(curPath[ele]){
                return true;
            }
        }

        // after the traversal of each node mark it false for the curpath
        curPath[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        

        //DETECT CYCLE IN A DIRECTED GRAPH

        //use visited and curPath vector such that if a node is visited then check in the 
        // curpath also it is present in curpath or not if it is present then there is a cycle 
        
        vector<vector<int>>adj(numCourses);

        for(auto ele : prerequisites){
            int u = ele[0];
            int v = ele[1];
            adj[v].push_back(u);
        }
        vector<bool>visited(numCourses,false);
        vector<bool>curPath(numCourses,false);

        for(int i = 0; i<numCourses; i++){
            if(!visited[i]){
                if(detect(i, visited, curPath, adj)){
                    return false;
                }
            }
        }
        return true;
    }
};