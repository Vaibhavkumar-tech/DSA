class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int prev1=0;
        int prev2=INT_MAX;
        int prev3=INT_MAX;
        for(int i=1;i<=n;i++){
            int curr=INT_MAX;
            if(prev1!=INT_MAX){
                curr=min(curr,prev1+costs[i-1]+1);
            }
            if(prev2!=INT_MAX){
                curr=min(curr,prev2+costs[i-1]+4);
            }
            if(prev3!=INT_MAX){
                curr=min(curr,prev3+costs[i-1]+9);
            }
            //think 5,6,7 curr=5 min of all
            prev3=prev2;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};