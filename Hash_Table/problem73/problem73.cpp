#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = static_cast<int>(matrix.size());
        const int n = static_cast<int>(matrix[0].size());
        bool row0 = false;
        bool col0 = false;
        for (int c = 0; c < n; ++c) {
            if (matrix[0][c] == 0) {
                row0 = true;
                break;
            }
        }
        for (int r = 0; r < m; ++r) {
            if (matrix[r][0] == 0) {
                col0 = true;
                break;
            }
        }
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }
        for (int r = 1; r < m; ++r) {
            if (matrix[r][0] == 0) {
                for (int c = 0; c < n; ++c) {
                    matrix[r][c] = 0;
                }
            }
        }
        for (int c = 1; c < n; ++c) {
            if (matrix[0][c] == 0) {
                for (int r = 0; r < m; ++r) {
                    matrix[r][c] = 0;
                }
            }
        }
        if (row0) {
            for (int c = 0; c < n; ++c) {
                matrix[0][c] = 0;
            }
        }
        if (col0) {
            for (int r = 0; r < m; ++r) {
                matrix[r][0] = 0;
            }
        }
    }
};
