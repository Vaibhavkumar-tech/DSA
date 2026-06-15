class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            //odd palindrone
            int l=i;
            int r=i;
            while(l >= 0 && r < n && s[l] == s[r]){
                l--;
                r++;
            }
            string palindrome=s.substr(l + 1, r - l - 1);
            if(ans.size()<palindrome.size()){
                ans=palindrome;
            }
            //even palindrone
            l=i-1;
            r=i;
            while(l >= 0 && r < n && s[l] == s[r]){
                l--;
                r++;
            }
            palindrome=s.substr(l + 1, r - l - 1);
            if(ans.size()<palindrome.size()){
                ans=palindrome;
            }
        }
        return ans;
    }
};