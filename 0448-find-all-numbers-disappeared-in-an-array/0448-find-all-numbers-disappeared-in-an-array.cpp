class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int>store(n+1,-1);
        vector<int>ans;
        for(int i=0;i<n;i++){
            store[nums[i]]++;
        }
        for(int i=1;i<store.size();i++){
            if(store[i]==-1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};