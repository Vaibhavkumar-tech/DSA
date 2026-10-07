class Solution {
public:
    int n;
    unordered_set<string> st;
    int maxLen;

    void solve(string& s, int i, string& curr, int count) {

        // Invalid: more ')' than '('
        if (count < 0)
            return;

        // Reached end
        if (i == n) {
            if (count == 0) {

                // Found a longer valid string
                if (curr.length() > maxLen) {
                    maxLen = curr.length();
                    st.clear();
                }

                // Store all valid strings of maximum length
                if (curr.length() == maxLen) {
                    st.insert(curr);
                }
            }
            return;
        }

        // -------------------------
        // Case 1: Normal character
        // -------------------------
        if (s[i] != ')' && s[i] != '(') {

            curr.push_back(s[i]);

            solve(s, i + 1, curr, count);

            curr.pop_back();
        }

        // -------------------------
        // Case 2: '('
        // -------------------------
        else if (s[i] == '(') {

            // Choice 1: Keep '('
            curr.push_back('(');

            solve(s, i + 1, curr, count + 1);

            curr.pop_back();

            // Choice 2: Remove '('
            solve(s, i + 1, curr, count);
        }

        // -------------------------
        // Case 3: ')'
        // -------------------------
        else {

            // Choice 1: Keep ')' only if
            // there is an unmatched '('
            if (count > 0) {

                curr.push_back(')');

                solve(s, i + 1, curr, count - 1);

                curr.pop_back();
            }

            // Choice 2: Remove ')'
            solve(s, i + 1, curr, count);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        n = s.length();
        st.clear();
        maxLen = 0;

        string curr = "";

        solve(s, 0, curr, 0);

        return vector<string>(st.begin(), st.end());
    }
};