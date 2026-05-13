#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = static_cast<int>(heights.size());
        int best = 0;
        vector<int> st;          // vector as stack: better cache locality than std::stack
        st.reserve(n + 1);

        for (int i = 0; i <= n; ++i) {
            int h = (i < n) ? heights[i] : 0;   // sentinel without modifying input
            while (!st.empty() && heights[st.back()] > h) {
                int height = heights[st.back()]; st.pop_back();
                int width  = st.empty() ? i : i - st.back() - 1;
                int area   = height * width;
                if (area > best) best = area;
            }
            st.push_back(i);
        }

        return best;
    }
};