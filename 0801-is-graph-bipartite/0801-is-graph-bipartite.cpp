class Solution {
public:
    bool helper(int node, int color, vector<vector<int>>& graph, vector<int>&colors){
        colors[node] = color;

        for(auto ele : graph[node]){
            //if it is not visited then mark it with different color and perfrom dfs
            if(colors[ele] == -1){
                //agar kahin se false aarha hai toh yahan bhi false return krdo
                if(!helper(ele, color^1, graph, colors))return false;
                //if ele is visited then check its color its same or not
            }else if(colors[ele] == colors[node])return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        //Start coloring it with 2 colors and if the adjascent node have the same color then it not bipartite
        int n = graph.size();
        vector<int>colors(n,-1);
        for(int i = 0 ; i < n ; i++){
            if(colors[i] == -1){
                if(!helper(i,0,graph,colors))return false;
            }
        }
        return true;

    }
};