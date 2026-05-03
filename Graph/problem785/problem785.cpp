#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = static_cast<int>(graph.size());
        vector<int> color(n, -1);

        for (int start = 0; start < n; ++start) {
            if (color[start] != -1) continue;
            color[start] = 0;
            queue<int> q;
            q.push(start);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int nb : graph[node]) {
                    if (color[nb] == -1) {
                        color[nb] = 1 - color[node];
                        q.push(nb);
                    } else if (color[nb] == color[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
