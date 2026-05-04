#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build adjacency list
        vector<vector<pair<int,int>>> graph(n);
        for (auto& f : flights)
            graph[f[0]].push_back({f[1], f[2]});

        // dist[i] = cheapest cost to reach city i found so far
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // BFS level by level: each level = one more flight (edge)
        // Queue holds {node, cost_to_reach_node}
        queue<pair<int,int>> q;
        q.push({src, 0});

        for (int i = 0; i <= k; i++) {  // at most k+1 edges = k stops
            int sz = q.size();
            // Process only nodes in the current level
            while (sz--) {
                auto [node, cost] = q.front(); q.pop();
                for (auto& [neighbor, price] : graph[node]) {
                    int new_cost = cost + price;
                    // Only enqueue if we found a cheaper path to neighbor
                    if (new_cost < dist[neighbor]) {
                        dist[neighbor] = new_cost;
                        q.push({neighbor, new_cost});
                    }
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};