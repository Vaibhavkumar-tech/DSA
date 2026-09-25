class Solution {
public:

    set<string> solve(string &s, int &i) {

        // This represents the UNION result
        set<string> ans;

        // This represents the current concatenation result
        set<string> cur;
        cur.insert("");

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                // Finish current concatenation
                ans.insert(cur.begin(), cur.end());

                // Start a new concatenation term
                cur.clear();
                cur.insert("");

                i++;
            }

            else if (s[i] == '{') {
                i++;  // skip '{'

                set<string> inside = solve(s, i);

                i++;  // skip '}'

                // Concatenate cur × inside
                set<string> temp;

                for (string a : cur) {
                    for (string b : inside) {
                        temp.insert(a + b);
                    }
                }

                cur = temp;
            }

            else {
                // Single letter
                string letter(1, s[i]);
                i++;

                set<string> temp;

                for (string a : cur) {
                    temp.insert(a + letter);
                }

                cur = temp;
            }
        }

        // Add the last concatenation term
        ans.insert(cur.begin(), cur.end());

        return ans;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> result = solve(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};