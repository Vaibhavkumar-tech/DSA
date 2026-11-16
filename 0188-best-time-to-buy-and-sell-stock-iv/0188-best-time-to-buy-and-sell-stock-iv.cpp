class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>after(2,vector<int>(k+1,0));
        vector<vector<int>>curr(2,vector<int>(k+1,0));
        //base cases
/*         1.cap==0 then idx and buy can be anything return 0;
        2.idx==n then cap and buy can be anything alsways return 0; */

        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<=k;cap++){
                    int price;
                    if(buy==1){
                        price=max(
                            -prices[idx]+after[0][cap],
                            0+after[1][cap]
                        );
                    }
                    else{
                        price=max(
                            prices[idx]+after[1][cap-1],
                            0+after[0][cap]
                        );
                    }
                    curr[buy][cap]=price;
                }
            }
            after=curr;
        }
        return after[1][k];
    }
};