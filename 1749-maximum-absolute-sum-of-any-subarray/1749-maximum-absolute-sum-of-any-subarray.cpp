class Solution {
public:
    int maxSum(vector<int>& nums,int n){
        int maxi=nums[0];
        int sum=nums[0];
        for(int i=1;i<n;i++){
            sum=max(nums[i],sum+nums[i]);
            maxi=max(maxi,sum);
        }
        return maxi;
    }
    int MinSum(vector<int>& nums,int n){
        int mini=nums[0];
        int sum=nums[0];
        for(int i=1;i<n;i++){
            sum=min(nums[i],sum+nums[i]);
            mini=min(mini,sum);
        }
        return mini;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        return max(maxSum(nums,nums.size()),abs(MinSum(nums,nums.size())));
    }
};