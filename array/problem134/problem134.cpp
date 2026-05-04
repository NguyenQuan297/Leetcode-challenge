#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        for (int i = 0; i < static_cast<int>(gas.size()); ++i) {
            total += gas[i] - cost[i];
        }
        if (total < 0) return -1;

        int tank = 0;
        int start = 0;
        for (int i = 0; i < static_cast<int>(gas.size()); ++i) {
            tank += gas[i] - cost[i];
            if (tank < 0) {
                tank = 0;
                start = i + 1;
            }
        }

        return start;
    }
};
