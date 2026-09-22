class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long MOD = 1e9 + 7;
        vector<vector<pair<int,int>>>adj(n);
        for(auto& it:roads){
            int u=it[0];
            int v=it[1];
            int time=it[2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        } 
        //dikstra algo
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0}); //{dist,u}  
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            long long d=it.first;
            int node=it.second;
            if(d>dist[node]) continue;
            for(auto val:adj[node]){
                int curr_node = val.first;
                int curr_d = val.second;
                long long newDist = d + curr_d;
                if(newDist<dist[curr_node]){
                    dist[curr_node]=newDist;
                    ways[curr_node] = ways[node];
                    pq.push({newDist,curr_node});
                }
                else if (newDist == dist[curr_node]) {
                    ways[curr_node] =(ways[curr_node] + ways[node]) % MOD;
                }
            }

        }
        return ways[n - 1];
    }
};