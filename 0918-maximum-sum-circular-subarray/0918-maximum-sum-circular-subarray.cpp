class Solution {
public:
    int kadaneMax(vector<int>& nums, int n) {
        int maxi = nums[0];
        int sum = nums[0];

        for (int i = 1; i < n; i++) {
            sum = max(nums[i], sum + nums[i]);
            maxi = max(maxi, sum);
        }
        return maxi;
    }

    int kadaneMin(vector<int>& nums, int n) {
        int mini = nums[0];
        int sum = nums[0];

        for (int i = 1; i < n; i++) {
            sum = min(nums[i], sum + nums[i]);
            mini = min(mini, sum);
        }
        return mini;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        int maxSum = kadaneMax(nums, nums.size());
        int minSum = kadaneMin(nums, nums.size());

        if (maxSum < 0) return maxSum; // all elements negative

        return max(maxSum, totalSum - minSum);
    }
};