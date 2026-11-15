class Solution {
public:

    int n;
    vector<vector<int>>dp;
    long long solve(vector<int>& prices,int idx,int buy){
        if(idx==n){
            return 0;
        }
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        long long price;
        if(buy){
            price=max(-prices[idx]+solve(prices,idx+1,0),solve(prices,idx+1,1));
        }
        else{
            price=max(prices[idx]+solve(prices,idx+1,1),solve(prices,idx+1,0));
        }

        return dp[idx][buy]=price;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        this->n=n;
        dp.resize(n,vector<int>(2,-1));
        return solve(prices,0,1);
    }
};