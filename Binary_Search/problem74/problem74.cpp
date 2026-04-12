#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Rows and columns form one sorted sequence: index k maps to matrix[k / n][k % n].
        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix[0].size());
        int lo = 0;
        int hi = m * n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int val = matrix[mid / n][mid % n];
            if (val == target) {
                return true;
            }
            if (val < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return false;
    }
};
