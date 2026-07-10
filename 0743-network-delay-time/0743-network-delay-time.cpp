class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &vec : times) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];

            adj[u].push_back({v, w});
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> result(n + 1, INT_MAX);

        result[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {

            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dist > result[node])
                continue;

            for (auto &edge : adj[node]) {

                int adjNode = edge.first;
                int weight = edge.second;

                if (dist + weight < result[adjNode]) {

                    result[adjNode] = dist + weight;
                    pq.push({result[adjNode], adjNode});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            if (result[i] == INT_MAX)
                return -1;

            ans = max(ans, result[i]);
        }

        return ans;
    }
};