class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double sum = 0;
        double ans = INT_MIN;
        int l=0;
        int r=0;
        while(r<n){
            sum+=nums[r];
            if(r-l+1==k){
                ans=max(ans,sum/(double)k);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return ans;
    }
};