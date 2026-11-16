class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        // dp[idx][buy]
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        // Base case:
        // idx == n -> profit = 0
        // Already initialized with 0.

        for(int idx = n - 1; idx >= 0; idx--) {

            for(int buy = 0; buy <= 1; buy++) {

                int profit = 0;

                if(buy == 1) {

                    // Buy or Skip
                    profit = max(
                        -prices[idx] + dp[idx + 1][0],
                        dp[idx + 1][1]
                    );

                }
                else {

                    // Sell or Hold
                    profit = max(
                        prices[idx] + dp[idx + 2][1],
                        dp[idx + 1][0]
                    );
                }

                dp[idx][buy] = profit;
            }
        }

        return dp[0][1];
    }
};