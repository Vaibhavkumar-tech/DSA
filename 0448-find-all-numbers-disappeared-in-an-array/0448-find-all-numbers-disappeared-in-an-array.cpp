class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int idx=abs(nums[i])-1; //minus due to 0 based indexing and hmm mark kr rha h -1 then idx should be +ve
            if(nums[idx]<0){
                continue;
            }
            nums[idx]*=-1;
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};