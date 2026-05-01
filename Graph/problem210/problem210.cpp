#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for (const auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            ++indegree[p[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;
        order.reserve(numCourses);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);
            for (int nb : adj[node]) {
                if (--indegree[nb] == 0) {
                    q.push(nb);
                }
            }
        }

        return static_cast<int>(order.size()) == numCourses ? order : vector<int>{};
    }
};
