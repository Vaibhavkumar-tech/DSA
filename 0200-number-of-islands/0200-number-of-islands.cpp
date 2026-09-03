class Solution {
public:
    vector<vector<int>> direction{{1,0}, {-1,0}, {0,1}, {0,-1}};
    int m;
    int n;

    void DFS(int i, int j, vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {
        
        visited[i][j] = true;

        for (auto& dir : direction) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (new_i >= 0 && new_i < m &&
                new_j >= 0 && new_j < n &&
                !visited[new_i][new_j] &&
                grid[new_i][new_j] == '1') {
                
                DFS(new_i, new_j, grid, visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (!visited[i][j] && grid[i][j] == '1') {
                    count++;  // Found a new island
                    DFS(i, j, grid, visited);
                }
            }
        }
        return count;
    }
};