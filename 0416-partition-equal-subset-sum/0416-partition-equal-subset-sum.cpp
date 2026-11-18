class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int ind, int target, vector<int>& nums, int sum) {

        if (sum == target) return true;
        if (ind < 0) return false;

        if (dp[ind][sum] != -1)
            return dp[ind][sum];

        bool take = false;

        if (sum + nums[ind] <= target)
            take = solve(ind - 1, target, nums, sum + nums[ind]);

        bool notTake = solve(ind - 1, target, nums, sum);

        return dp[ind][sum] = (take || notTake);
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;

        for (int x : nums)
            totalSum += x;

        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        int n = nums.size();

        dp.assign(n, vector<int>(target + 1, -1));

        return solve(n - 1, target, nums, 0);
    }
};