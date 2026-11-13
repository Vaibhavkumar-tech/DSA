
class Solution {
public:
    int n;
    vector<int> dp;
/*     vector<vector<bool>> visited;

    int solve(vector<vector<int>>& triangle, int i, int j) {

        // Base case
        if (i == n - 1) {
            return triangle[i][j];
        }

        // Already calculated
        if (visited[i][j]) {
            return dp[i][j];
        }

        // Down
        int down = solve(triangle, i + 1, j);

        // Diagonal right
        int right = solve(triangle, i + 1, j + 1);

        // Store answer
        visited[i][j] = true;

        return dp[i][j] = triangle[i][j] + min(down, right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        n = triangle.size();

        dp.assign(n, vector<int>(n, 0));
        visited.assign(n, vector<bool>(n, false));

        return solve(triangle, 0, 0);
    } */
    int minimumTotal(vector<vector<int>>& triangle) {

        n = triangle.size();

        dp.assign(n, 0);
        for(int i=0;i<n;i++){
            dp[i]=triangle[n-1][i];
        }

        for(int i=n-2;i>=0;i--){
            vector<int>curr(i+1,0);
            for(int j=i;j>=0;j--){
                int down=dp[j];
                int right=dp[j+1];
                curr[j]=triangle[i][j]+min(down,right);
            }
            dp=curr;
        }
        return dp[0];
    }
};
