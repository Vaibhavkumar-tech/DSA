class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<pair<int,int>> adj[n];

        // Build graph
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        int ans = -1;
        int minCount = INT_MAX;

        // Run Dijkstra from every city
        for (int src = 0; src < n; src++) {

            vector<int> dist(n, 1e9);

            priority_queue<
                pair<int,int>,
                vector<pair<int,int>>,
                greater<pair<int,int>>
            > pq;

            dist[src] = 0;
            pq.push({0, src});

            while (!pq.empty()) {

                auto [cost, node] = pq.top();
                pq.pop();

                // Ignore outdated value
                if (cost > dist[node])
                    continue;

                for (auto it : adj[node]) {

                    int adjNode = it.first;
                    int wt = it.second;

                    if (cost + wt < dist[adjNode]) {

                        dist[adjNode] = cost + wt;

                        pq.push({
                            dist[adjNode],
                            adjNode
                        });
                    }
                }
            }

            // Count cities within threshold
            int count = 0;

            for (int i = 0; i < n; i++) {

                if (i != src && dist[i] <= distanceThreshold) {
                    count++;
                }
            }

            // Same count -> choose larger city
            if (count <= minCount) {
                minCount = count;
                ans = src;
            }
        }

        return ans;
    }
};