class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int l=0;
        int maxi=1;
        for(int r=1;r<n;r++){
            int a=nums[r-1];
            int b=nums[r];
            if(a==b){
                l=r;
            }
            if(r==n-1 || (a>b && b>=nums[r+1]) || (a<b && b<=nums[r+1])){
                maxi=max(maxi,r-l+1);
                l=r;
            }
        }
        return maxi;
    }
};