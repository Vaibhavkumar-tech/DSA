class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;

        for (char c : s) {
            if (c == '(') {
                // If count > 0, this is NOT an outermost '('
                if (count > 0) {
                    ans += c;
                }

                count++;
            }
            else {
                count--;

                // If count > 0, this is NOT an outermost ')'
                if (count > 0) {
                    ans += c;
                }
            }
        }

        return ans;
    }
};