
class Solution {
public:
/*     int m, n;
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
    } */
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>prev(n,0);
        for(int i=0;i<n;i++){
            prev[i]=matrix[m-1][i];
        }
        for(int i=m-2;i>=0;i--){
            vector<int>curr(n,0);
            for(int j=n-1;j>=0;j--){

                int down = prev[j];
                int left=INT_MAX;
                int right=INT_MAX;
                if(j>0){
                left = prev[j-1];}
                if(j<n-1){
                right =prev[j+1]; }

                curr[j] = matrix[i][j] +min({down, left, right});
            }
            prev=curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};
