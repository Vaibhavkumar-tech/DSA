class Solution {
public:

    struct State {
        long long score;
        vector<int> indices;
    };

    State better(const State& a, const State& b) {

        // Higher score is better
        if (a.score != b.score) {
            return a.score > b.score ? a : b;
        }

        // Same score:
        // lexicographically smaller indices are better
        if (lexicographical_compare(
                a.indices.begin(), a.indices.end(),
                b.indices.begin(), b.indices.end())) {
            return a;
        }

        return b;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // {left, right, weight, original index}
        vector<array<int, 4>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by left endpoint
        sort(arr.begin(), arr.end());

        // next[i] = first interval whose left > arr[i].right
        vector<int> next(n);

        for (int i = 0; i < n; i++) {

            int lo = i + 1;
            int hi = n;

            while (lo < hi) {

                int mid = lo + (hi - lo) / 2;

                if (arr[mid][0] > arr[i][1])
                    hi = mid;
                else
                    lo = mid + 1;
            }

            next[i] = lo;
        }

        // dp[i][k]
        // Best answer starting from i
        // using at most k intervals
        vector<vector<State>> dp(
            n + 1,
            vector<State>(5)
        );

        // Base case
        for (int k = 0; k <= 4; k++) {
            dp[n][k] = {0, {}};
        }

        // DP
        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // 1. Skip current interval
                State skip = dp[i + 1][k];

                // 2. Take current interval
                State take = dp[next[i]][k - 1];

                take.score += arr[i][2];

                take.indices.push_back(arr[i][3]);

                // IMPORTANT:
                // Keep original indices sorted
                sort(
                    take.indices.begin(),
                    take.indices.end()
                );

                // Choose better option
                dp[i][k] = better(skip, take);
            }
        }

        return dp[0][4].indices;
    }
};