#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);
        triangle[0] = {1};

        for (int i = 1; i < numRows; ++i) {
            const auto& prev = triangle[i - 1];
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                row[j] = prev[j - 1] + prev[j];
            }
            triangle[i] = move(row);
        }

        return triangle;
    }
};
