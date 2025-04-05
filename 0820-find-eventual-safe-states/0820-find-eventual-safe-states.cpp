class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // Got to know that it is the matter of outdegree as 6 is marked as safe and 5 also then we will figure out which node can be safe by going backward using the edge and removing the edge or we can say outdegree. Thus we are reversing the edges and using indegree we are computing

        //Reverse the edges which then perform Kahn's algo.
        //It will only touch that node only which are not in cycle

        int n = graph.size();
        vector<vector<int>>rev(n);
        vector<int>indegree(n,0);

        for(int i = 0; i < graph.size(); i++){
            for(auto ele : graph[i]){
                rev[ele].push_back(i);
                indegree[i]++;
            }
        }

        //perform topo sort using kahn's algo

        queue<int>q;
        for(int i = 0 ; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>res;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            res.push_back(cur);

            for(auto ele : rev[cur]){
                indegree[ele]--;

                if(indegree[ele] == 0){
                    q.push(ele);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};