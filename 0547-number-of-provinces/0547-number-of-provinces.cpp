class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected,
        vector<int>& visited) {
        visited[city] = 1;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[city][i] == 1 && !visited[i]) {
                dfs(i, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int provinces = 0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                provinces++;
                dfs(i, isConnected, visited);
            }
        }
        return provinces;
    }
};