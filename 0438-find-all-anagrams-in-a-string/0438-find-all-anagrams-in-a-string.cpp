class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        vector<int>pFreq(26,0);
        vector<int>sFreq(26,0);
        vector<int>ans;
        for(auto val:p){
            pFreq[val-'a']++;
        }
        int l=0;
        int r=0;
        while(r<n){
            sFreq[s[r]-'a']++;
            if(r-l+1==p.size()){
                if(pFreq==sFreq){
                    ans.push_back(l);
                }
                sFreq[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return ans;
    }
};