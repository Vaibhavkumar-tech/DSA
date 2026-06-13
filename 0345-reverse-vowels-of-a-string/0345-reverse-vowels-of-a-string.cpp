class Solution {
public:

    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || 
               ch == 'i' || ch == 'o' || 
               ch == 'u';
    }
    string reverseVowels(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            while (l < r && !isVowel(s[l])) {
                l++;
            }
            while (l < r && !isVowel(s[r])) {
                r--;
            }
            swap(s[l], s[r]);
            l++;
            r--;
        }
        return s;
    }
};