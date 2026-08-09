#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* links[2];

    Node() {
        links[0] = links[1] = nullptr;
    }

    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }

    Node* get(int bit) {
        return links[bit];
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }

            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int maxi = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (node->containsKey(1 - bit)) {
                maxi |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }

        return maxi;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

        sort(nums.begin(), nums.end());

        vector<tuple<int,int,int>> q;

        for (int i = 0; i < queries.size(); i++) {
            int xi = queries[i][0];
            int mi = queries[i][1];

            q.push_back({mi, xi, i});
        }

        sort(q.begin(), q.end());

        Trie trie;
        vector<int> ans(queries.size());

        int idx = 0;
        int n = nums.size();

        for (auto &[mi, xi, originalIndex] : q) {

            while (idx < n && nums[idx] <= mi) {
                trie.insert(nums[idx]);
                idx++;
            }

            if (idx == 0) {
                ans[originalIndex] = -1;
            } else {
                ans[originalIndex] = trie.getMax(xi);
            }
        }

        return ans;
    }
};