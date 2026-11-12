class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int dec=1;
        int inc=1;
        int ans=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                //dec
                dec++;
                inc=1;
            }
            else if(nums[i-1]<nums[i]){
                inc++;
                dec=1;
            }
            else{
                inc=1;
                dec=1;
            }

            ans=max(ans,max(dec,inc));
        }
        return  ans;
    }
};