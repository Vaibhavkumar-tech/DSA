class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        for(int l=0;l<=n-m;l++){
            int r=0;
            while(r<m && haystack[l+r]==needle[r]){
                r++;
            }
            if(r==m){
                return l;
            }
        }
        return -1;
    }
};