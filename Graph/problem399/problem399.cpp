#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries
    ) {
        unordered_map<string, vector<pair<string, double>>> graph;

        for (int i = 0; i < static_cast<int>(equations.size()); ++i) {
            const string& a = equations[i][0];
            const string& b = equations[i][1];
            double v = values[i];
            graph[a].push_back({b, v});
            graph[b].push_back({a, 1.0 / v});
        }

        auto bfs = [&](const string& src, const string& dst) -> double {
            if (!graph.count(src) || !graph.count(dst)) return -1.0;
            if (src == dst) return 1.0;

            unordered_set<string> visited;
            queue<pair<string, double>> q;
            q.push({src, 1.0});
            visited.insert(src);

            while (!q.empty()) {
                auto [node, prod] = q.front();
                q.pop();
                for (const auto& [nb, w] : graph[node]) {
                    if (nb == dst) return prod * w;
                    if (!visited.count(nb)) {
                        visited.insert(nb);
                        q.push({nb, prod * w});
                    }
                }
            }
            return -1.0;
        };

        vector<double> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            ans.push_back(bfs(q[0], q[1]));
        }
        return ans;
    }
};
