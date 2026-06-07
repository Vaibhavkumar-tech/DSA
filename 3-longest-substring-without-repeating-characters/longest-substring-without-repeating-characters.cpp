class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, maxi = 0;

        map<char, int> hash;

        for (int r = 0; r < n; r++) {
            
            // If character seen before
            if (hash.find(s[r]) != hash.end() && hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }

            // Update last occurrence
            hash[s[r]] = r;

            // Update max length
            maxi = max(maxi, r - l + 1);
        }

        return maxi;
    }
};