class Solution {
public:
    int dp[1001][1001];

    int Solve(int i, int j, string &s, string &t) {
        
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == t[j]) {
            int pick = Solve(i + 1, j + 1, s, t);
            int skip = Solve(i + 1, j, s, t);

            return dp[i][j] = pick + skip;
        }

        int skip = Solve(i + 1, j, s, t);

        return dp[i][j] = skip;
    }

    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));

        return Solve(0, 0, s, t);
    }
};