class Solution {
public:

    int timer = 0;

    void dfs(int node, int parent,
             vector<int>& vis,
             vector<vector<int>>& adj,
             vector<int>& tin,
             vector<int>& low,
             vector<vector<int>>& bridges) {

        vis[node] = 1;

        tin[node] = low[node] = timer;
        timer++;

        for (auto it : adj[node]) {

            // Don't go back through the same edge
            if (it == parent)
                continue;

            // If it is an unvisited node
            if (vis[it] == 0) {

                dfs(it, node, vis, adj, tin, low, bridges);

                // Update low value after DFS
                low[node] = min(low[node], low[it]);//8 mein update kr dege if 9 ka steps ka kaam huwa

                // Bridge condition
                if (low[it] > tin[node]) {
                    //lowest steps to reach...min steps to reach that child-->10 steps
                    //tin->max max step we can reach to that node -->8 steps
                    //not possible to reach that it;
                    bridges.push_back({node, it});
                }
            }

            // Back edge
            else {
                low[node] = min(low[node], tin[it]);
            }
        }
    }

public:

    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections
    ) {

        vector<vector<int>> adj(n);

        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        vector<int> tin(n);
        vector<int> low(n);

        vector<vector<int>> bridges;

        dfs(0, -1, vis, adj, tin, low, bridges);

        return bridges;
    }
};