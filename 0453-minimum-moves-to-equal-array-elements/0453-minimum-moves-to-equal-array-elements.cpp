class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());

        int steps = 0;

        for(int i = 0; i < nums.size(); i++) {
            steps += nums[i] - mini;
        }

        return steps;
    }
};