#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Each row is sorted: binary search within the row (O(log n) per row).
        // Column order lets us skip rows or stop early (O(m log n) overall).
        for (const auto& row : matrix) {
            if (row.front() > target) {
                break;
            }
            if (row.back() < target) {
                continue;
            }
            int lo = 0;
            int hi = static_cast<int>(row.size()) - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (row[mid] == target) {
                    return true;
                }
                if (row[mid] < target) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return false;
    }
};
