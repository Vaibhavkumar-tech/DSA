class Solution {
public:
    bool DFS(int node,int paint,vector<vector<int>>& graph,vector<int>& color){
        color[node]=paint;
        for(auto nodes:graph[node]){
            if(color[nodes]==-1){
              if(DFS(nodes,!paint,graph,color)==false) return false;
            }
            else if(color[nodes]==paint) return false;
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(DFS(i,0,graph,color)==false) return false;
            }
        }
        return true;
    }
};