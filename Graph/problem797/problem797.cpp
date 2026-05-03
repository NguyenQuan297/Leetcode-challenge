#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = static_cast<int>(graph.size());
        int target = n - 1;
        vector<vector<int>> result;

        // Iterative DFS: stack stores (current_node, path_so_far)
        // Using move semantics avoids path copying on push
        vector<pair<int, vector<int>>> stk;
        stk.push_back({0, {0}});
        stk.back().second.reserve(n);

        while (!stk.empty()) {
            auto [node, path] = move(stk.back());
            stk.pop_back();

            if (node == target) {
                result.push_back(move(path));
                continue;
            }

            for (int nb : graph[node]) {
                vector<int> newPath = path;
                newPath.push_back(nb);
                stk.push_back({nb, move(newPath)});
            }
        }

        return result;
    }
};
