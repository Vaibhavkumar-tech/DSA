class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0); //always remember to write
        for(int i=1;i<n+1;i++){
            int bit=(i & i-1);
            ans[i]=ans[bit]+1;
        }
        return ans;
    }
};