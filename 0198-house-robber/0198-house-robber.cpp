class Solution {
public:
    vector<int>dp;
    int Solve(vector<int>& nums,int idx){
        if(idx==0) return nums[idx];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        //pick
        int pick=nums[idx]+Solve(nums,idx-2);
        //not pick
        int notpick=0+Solve(nums,idx-1);
        return dp[idx]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,-1);
        return Solve(nums,n-1);
    }
};