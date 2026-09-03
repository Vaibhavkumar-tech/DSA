class Solution {
public: 
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int min=*min_element(nums1.begin(),nums1.end());
        if(min%2!=0) return true;
        for(int i=0;i<n;i++){
            if(nums1[i]%2!=0) return false;
        }
        return true;
    }
};