class Solution {
public:
    int n;
    vector<vector<vector<int>>>dp;
    int solve(vector<int>& prices,int idx,int cap,int buy){
        if(cap==0) return 0;
        if(idx==n) return 0;

        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
        int price=0;
        //buy
        if(buy){
            price=max(
                -prices[idx]+solve(prices,idx+1,cap,0),
                0+solve(prices,idx+1,cap,1)
            );
        }
        else{
            price=max(
                prices[idx]+solve(prices,idx+1,cap-1,1),
                0+solve(prices,idx+1,cap,0)
            );
        }
        return dp[idx][buy][cap]=price;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        this->n=n;
        dp.resize(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,2,1);
        
    }
};