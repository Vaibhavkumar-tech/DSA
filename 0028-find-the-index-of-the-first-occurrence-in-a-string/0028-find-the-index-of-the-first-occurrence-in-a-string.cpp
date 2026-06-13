class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        int l=0;
        int r=m-1;
        while(r<n){
            if(haystack.substr(l,m)==needle){
                return l;
            }
            l++;
            r++;
        }
        return -1;
    }
};