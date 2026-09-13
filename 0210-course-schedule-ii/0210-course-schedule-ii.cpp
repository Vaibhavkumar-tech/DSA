class Solution {
public:

    vector<int> topologicalSortedCheck(
        unordered_map<int, vector<int>>& adj,
        int n,
        vector<int>& indegree
    ) {
        queue<int> q;
        vector<int> result;

        // Push all nodes having indegree 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Kahn's Algorithm
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            result.push_back(u);

            for (int& v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // If all courses are processed, valid ordering exists
        if (result.size() == n) {
            return result;
        }

        // Cycle exists
        return {};
    }

    vector<int> findOrder(int numCourses,
        vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        for (auto& vec : prerequisites) {
            int course = vec[0];
            int prerequisite = vec[1];

            // prerequisite -> course
            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        return topologicalSortedCheck(
            adj,
            numCourses,
            indegree
        );
    }
};