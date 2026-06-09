class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        int jumps = 0;
        int currEnd = 0;
        int farthest = 0;

        for(int i = 0; i < n - 1; i++) {

            // Find farthest reachable index
            farthest = max(farthest, i + nums[i]);

            // Current jump range finished
            if(i == currEnd) {

                jumps++;

                currEnd = farthest;
            }
        }

        return jumps;
    }
};