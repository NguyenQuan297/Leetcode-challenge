#include <vector>

using namespace std;

class Solution {
    // Largest rectangle in histogram — O(n), inline sentinel, vector stack
    static int histogramMax(vector<int>& h) {
        int n    = static_cast<int>(h.size());
        int best = 0;
        vector<int> st;
        st.reserve(n + 1);

        for (int i = 0; i <= n; ++i) {
            int cur = (i < n) ? h[i] : 0;
            while (!st.empty() && h[st.back()] > cur) {
                int height = h[st.back()]; st.pop_back();
                int width  = st.empty() ? i : i - st.back() - 1;
                int area   = height * width;
                if (area > best) best = area;
            }
            st.push_back(i);
        }
        return best;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int rows = static_cast<int>(matrix.size());
        int cols = static_cast<int>(matrix[0].size());

        vector<int> heights(cols, 0);
        int best = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                heights[c] = (matrix[r][c] == '1') ? heights[c] + 1 : 0;
            }
            int area = histogramMax(heights);
            if (area > best) best = area;
        }

        return best;
    }
};
