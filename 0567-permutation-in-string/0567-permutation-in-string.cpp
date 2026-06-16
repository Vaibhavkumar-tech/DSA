class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>s1Freq(26,0);
        vector<int>s2Freq(26,0);
        for(auto val:s1){
            s1Freq[val-'a']++;
        }
        int l=0;
        int r=0;
        int n=s2.size();
        while(r<n){
            s2Freq[s2[r]-'a']++;
            if(r-l+1==s1.size()){
                if(s1Freq==s2Freq){
                    return true;
                }
                s2Freq[s2[l]-'a']--;
                l++;
            }
            r++;
        }
        return false;
    }
};