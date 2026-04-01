#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Take all increasing segments: sum of positive deltas
        int profit = 0;
        for (int i = 1; i < static_cast<int>(prices.size()); ++i) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};
