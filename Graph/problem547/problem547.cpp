#include <numeric>
#include <vector>

using namespace std;

class Solution {
    vector<int> parent, rank_;

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        if (rank_[rx] < rank_[ry]) swap(rx, ry);
        parent[ry] = rx;
        if (rank_[rx] == rank_[ry]) ++rank_[rx];
        return true;
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = static_cast<int>(isConnected.size());
        parent.resize(n);
        rank_.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
        int count = n;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j] && unite(i, j)) {
                    --count;
                }
            }
        }

        return count;
    }
};
