
class Solution {
public:
    vector<int> DP;
    int m;
    int Recursion(int idx) {
        if (idx == m) return 1;
        if (idx > m) return 0;
        if (DP[idx] != -1) return DP[idx];
        int left = Recursion(idx + 1);
        int right = Recursion(idx + 2);
        return DP[idx] = left + right;
    }
    int climbStairs(int n) {
        m = n;
        DP.resize(n + 1, -1);
        return Recursion(0);
    }
};
