class Solution {
public: 
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        unordered_map<int,int>mp;
        long long maxi=0; //m
        int n=nums.size();
        long long sum=0; //m
        while(r<n){
            mp[nums[r]]++;
            sum+=nums[r];
            if(r-l+1==k){
                if(mp.size()==k){
                    maxi=max(maxi,sum);
                }
                sum-=nums[l];
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]); //m
                }
                l++;
            }
            r++;
        }
        return maxi;
    }
};