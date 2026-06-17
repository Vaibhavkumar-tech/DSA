class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, maxi = 0;
        unordered_map<char, int> freq;
        for (int r = 0; r < n; r++) {
            if (freq.find(s[r]) != freq.end()) {
                l = max(l, freq[s[r]] + 1); //importnt line
            }
            freq[s[r]] = r;
            maxi = max(maxi, r - l + 1);
        }
        return maxi;
    }
};