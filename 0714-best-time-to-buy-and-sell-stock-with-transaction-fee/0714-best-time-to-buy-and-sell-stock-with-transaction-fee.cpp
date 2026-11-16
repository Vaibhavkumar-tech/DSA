class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        vector<long long> ahead(2, 0);
        vector<long long> cur(2, 0);

        for (int ind = n - 1; ind >= 0; ind--) {

            for (int buy = 0; buy <= 1; buy++) {

                long long profit = 0;

                if (buy) {
                    // Buy or Skip
                    profit = max(
                        -1LL * prices[ind] + ahead[0],
                        ahead[1]
                    );
                }
                else {
                    // Sell or Hold
                    profit = max(
                        1LL * prices[ind] + ahead[1]-fee,
                        ahead[0]
                    );
                }

                cur[buy] = profit;
            }

            ahead = cur;
        }

        return ahead[1];
    }
};