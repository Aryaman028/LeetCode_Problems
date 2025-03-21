class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> indegree;
        unordered_map<string, vector<string>> graph;
        set<string> supplySet(supplies.begin(), supplies.end());
        vector<string> res;

        // Create graph and calculate indegrees
        for (int i = 0; i < recipes.size(); i++) {
            for (auto& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }

        // Initialize queue with supplies
        queue<string> q;
        for (auto& supply : supplies) {
            q.push(supply);
        }

        // Process the graph
        while (!q.empty()) {
            string current = q.front();
            q.pop();

            // If the current item is a recipe, add it to the result
            if (indegree.find(current) != indegree.end()) {
                res.push_back(current);
            }

            // Process its dependencies
            for (auto& next : graph[current]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        return res;
    }
};
