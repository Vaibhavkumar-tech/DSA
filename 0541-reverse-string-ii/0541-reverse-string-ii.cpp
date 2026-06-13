class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i=0;i<n;i+=2*k) {
            reverse(s.begin() + i,s.begin() + min(i + k, n));  //reverse mein excluding of end index
        }
        return s;
    }
};