class Solution {
public:
    using P = pair<int, pair<int, int>>;

    vector<vector<int>> directions{
        {0,1},
        {0,-1},
        {1,0},
        {-1,0}
    };

    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(
            n, vector<int>(m, INT_MAX)
        );

        priority_queue<
            P,
            vector<P>,
            greater<P>
        > pq;

        dist[0][0] = 0;

        // {effort, {row, col}}
        pq.push({0, {0, 0}});

        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int effort = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if (x == n-1 && y == m-1) {
                return effort;
            }

            // Explore 4 directions
            for (auto& dir : directions) {

                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if (new_x >= 0 && new_x < n &&
                    new_y >= 0 && new_y < m) {

                    // Difference between current and next cell
                    int edgeWeight = abs(
                        heights[x][y] -
                        heights[new_x][new_y]
                    );

                    // Maximum difference encountered so far
                    int newEffort = max(
                        effort,
                        edgeWeight
                    );

                    if (dist[new_x][new_y] > newEffort) {

                        dist[new_x][new_y] = newEffort;

                        pq.push({
                            newEffort,
                            {new_x, new_y}
                        });
                    }
                }
            }
        }

        return -1;
    }
};