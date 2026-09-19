class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1], it[2]}); //0->kaha ja rha h aur cost ex-> 0--->{1,30},{2,40}
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9);
        q.push({0,{src,0}});
        dist[src]=0;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stop=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stop>k) continue;
            for(auto val:adj[node]){
                int Nextnode=val.first;
                int Onecost=val.second;
                if(Onecost+cost<dist[Nextnode] && stop<=k){
                    dist[Nextnode]=Onecost+cost;
                    q.push({stop+1,{Nextnode,Onecost+cost}});
                }
            }
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};