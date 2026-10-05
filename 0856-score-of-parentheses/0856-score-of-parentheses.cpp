class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } 
            else {
                int x = st.top();
                st.pop();

                if (x == 0) {
                    // ()
                    st.top() += 1;
                } 
                else {
                    // (A)
                    st.top() += 2 * x;
                }
            }
        }

        return st.top();
    }
};