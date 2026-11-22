class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=stones[i];
        }
        int k = totalSum;
        vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        if (stones[0] <= k)
            dp[0][stones[0]] = true;

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {

                bool notTake = dp[ind - 1][target];

                bool take = false;

                if (stones[ind] <= target)
                    take = dp[ind - 1][target - stones[ind]];

                dp[ind][target] = take | notTake;
            }
        }

        int mini=INT_MAX;
        //for last one is posible or not
        for(int s1=0;s1<=totalSum/2;s1++){
            if(dp[n-1][s1]==true){
                mini=min(mini,abs((totalSum-s1)-s1));
            }
        }
        return mini;
    }
};