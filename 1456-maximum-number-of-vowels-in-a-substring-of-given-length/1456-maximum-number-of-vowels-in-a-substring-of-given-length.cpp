class Solution {
public:
    bool Isvowel(char s){
        if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u'){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int maxi=INT_MIN;
        int l=0;
        int r=0;
        int n=s.size();
        int count=0;
        while(r<n){
            if(Isvowel(s[r])){
                count++;
            }
            if(r-l+1==k){
                maxi=max(maxi,count);
                if(Isvowel(s[l])){
                    count--;
                }
                l++;
            }
            r++;
        }
        return maxi;
    }
};