
class Solution {
public:
    vector<int> DP;

    int Recursion(int idx) {
        if (idx == 0 || idx == 1) return 1;

        if (DP[idx] != -1) return DP[idx];

        int left = Recursion(idx - 1);
        int right = Recursion(idx - 2);

        return DP[idx] = left + right;
    }

    int climbStairs(int n) {
        DP.resize(n + 1, -1);
        return Recursion(n);
    }
};
