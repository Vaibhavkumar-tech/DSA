class Solution {
public:
    int n;
    vector<vector<vector<int>>>dp;
/*     int solve(vector<int>& prices,int idx,int cap,int buy){
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
    } */
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        this->n=n;
        dp.resize(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        //base cases
/*         1.cap==0 then idx and buy can be anything return 0;
        2.idx==n then cap and buy can be anything alsways return 0; */

        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<3;cap++){
                    int price;
                    if(buy==1){
                        price=max(
                            -prices[idx]+dp[idx+1][0][cap],
                            0+dp[idx+1][1][cap]
                        );
                    }
                    else{
                        price=max(
                            prices[idx]+dp[idx+1][1][cap-1],
                            0+dp[idx+1][0][cap]
                        );
                    }
                    dp[idx][buy][cap]=price;
                }
            }
        }
        return dp[0][1][2];
        
    }
};