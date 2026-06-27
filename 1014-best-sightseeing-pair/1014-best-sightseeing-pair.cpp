class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        int ans=nums[0];
        for(int r=1;r<n;r++){
            ans=max(ans,maxi+nums[r]-r);
            maxi=max(maxi,nums[r]+r);
        }
        return ans;
    }
};