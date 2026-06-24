class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ') {//trailing space ignore kr diya
            i--;
        }
        int count = 0;
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }
        return count;
    }
};