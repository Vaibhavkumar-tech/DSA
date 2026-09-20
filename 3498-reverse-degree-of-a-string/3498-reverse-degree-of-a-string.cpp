class Solution {
public:
    int reverseDegree(string s) {
        int size = s.length();
        int sum = 0;

        for (int i = 0; i < size; i++) {
            int s1 = (26 - (s[i] - 'a')) * (i + 1);
            sum += s1;
        }

        return sum;
    }
};