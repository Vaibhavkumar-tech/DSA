class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        int maxi=arr[0];
        int prevNotDelete=arr[0];
        int prevDelete=0;
        for(int i=1;i<n;i++){
            prevDelete=max(prevNotDelete,prevDelete+arr[i]);
            prevNotDelete = max(arr[i], prevNotDelete + arr[i]);
            maxi=max(maxi,max(prevNotDelete,prevDelete));
        }
        return maxi;
    }
};