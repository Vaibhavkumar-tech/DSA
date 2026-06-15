class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        vector<int>freq(n+1,0);
        for(int i=0;i<n;i++){
            int number=nums[i];
            freq[number]++;
            if(freq[number]>1){
                ans=number;
                return ans;
            }
        }
        return ans;
    }
};