class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mpp;
        vector<int>ans;
        for(int i=0;i<nums2.size();i++){
            mpp[nums2[i]]++;
        }
        for(int i=0;i<nums1.size();i++){
            if(mpp.find(nums1[i])!=mpp.end()){
                ans.push_back(nums1[i]);
                mpp[nums1[i]]--;
                if(mpp[nums1[i]]==0){
                    mpp.erase(nums1[i]);
                }
            }
        }
        return ans;
    }
};