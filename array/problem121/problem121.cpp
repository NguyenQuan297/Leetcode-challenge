#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // One pass: keep cheapest buy price and best sell profit
        int minPrice = prices[0];
        int best = 0;
        for (int i = 1; i < static_cast<int>(prices.size()); ++i) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                best = max(best, prices[i] - minPrice);
            }
        }
        return best;
    }
};
