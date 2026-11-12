
class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    vector<vector<bool>> visited;

    int solve(vector<vector<int>>& matrix, int i, int j) {

        // Column boundary
        if(j < 0 || j >= n) return INT_MAX;

        // Last row
        if(i == m-1) {
            return matrix[i][j];
        }

        // Already calculated
        if(visited[i][j]) {
            return dp[i][j];
        }

        visited[i][j] = true;

        int down = solve(matrix, i+1, j);
        int left = solve(matrix, i+1, j-1);
        int right = solve(matrix, i+1, j+1);

        return dp[i][j] = matrix[i][j] +
                          min({down, left, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        m = matrix.size();
        n = matrix[0].size();

        dp.resize(m, vector<int>(n, 0));
        visited.resize(m, vector<bool>(n, false));

        int ans = INT_MAX;

        for(int j = 0; j < n; j++) {
            ans = min(ans, solve(matrix, 0, j));
        }

        return ans;
    }
};
