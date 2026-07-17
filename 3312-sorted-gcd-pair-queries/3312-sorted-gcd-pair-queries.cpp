class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> freq(maxi + 1, 0);

        for (int val : nums)
            freq[val]++;

        vector<long long> exact(maxi + 1, 0);

        // Count pairs divisible by i
        for (int i = 1; i <= maxi; i++) {

            long long cnt = 0;

            for (int j = i; j <= maxi; j += i)
                cnt += freq[j];

            exact[i] = cnt * (cnt - 1) / 2;
        }

        // Inclusion Exclusion
        for (int i = maxi; i >= 1; i--) {

            for (int j = 2 * i; j <= maxi; j += i)
                exact[i] -= exact[j];
        }

        vector<long long> prefix(maxi + 1, 0);

        for (int i = 1; i <= maxi; i++)
            prefix[i] = prefix[i - 1] + exact[i];

        vector<int> ans;

        for (long long q : queries) {
            int gcdValue =
                upper_bound(prefix.begin(), prefix.end(), q) - prefix.begin();

            ans.push_back(gcdValue);
        }

        return ans;
    }
};