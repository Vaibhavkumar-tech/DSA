class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto val:mp){
            if(val.second>1){
                ans=val.first;
               return ans;
            }
        }
        return ans;
    }
};