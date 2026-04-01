#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // DP with 4 states for at most 2 transactions
        long long buy1 = -(1LL << 60);
        long long sell1 = 0;
        long long buy2 = -(1LL << 60);
        long long sell2 = 0;

        for (int p : prices) {
            buy1 = max(buy1, -1LL * p);
            sell1 = max(sell1, buy1 + p);
            buy2 = max(buy2, sell1 - p);
            sell2 = max(sell2, buy2 + p);
        }
        return static_cast<int>(sell2);
    }
};
