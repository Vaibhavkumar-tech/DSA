class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxidx=0;
        for(int i=0;i<n;i++){
            if(maxidx<i) return false;//hmm usse idex tak pauche nhi paaye
            maxidx=max(maxidx,i+nums[i]);  //if no zero condition always reach to end
        }
        return true;
    }
};