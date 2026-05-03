#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = 1e9;
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(n + 1, INF);
        vector<bool> visited(n + 1, false);
        dist[k] = 0;

        // Array-based Dijkstra: O(V²) — optimal for n <= 100
        for (int iter = 0; iter < n; ++iter) {
            int u = -1;
            for (int i = 1; i <= n; ++i) {
                if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                    u = i;
                }
            }
            if (dist[u] == INF) break;
            visited[u] = true;
            for (const auto& [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == INF ? -1 : ans;
    }
};
