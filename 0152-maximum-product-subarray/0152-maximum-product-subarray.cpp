class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int left=1;
        int right=1;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(left==0) left=1;
            if(right==0) right=1;
            left*=nums[i];
            right*=nums[n-i-1];
            maxi=max(maxi,max(right,left));
        }
        return maxi;
    }
};