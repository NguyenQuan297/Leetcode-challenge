#include <string>
#include <vector>

using namespace std;

class Solution {
    int n_, full_;
    vector<int> queens_;
    vector<vector<string>> result_;

    void bt(int cols, int d1, int d2) {
        if (cols == full_) {
            vector<string> board(n_, string(n_, '.'));
            for (int r = 0; r < n_; ++r) board[r][queens_[r]] = 'Q';
            result_.push_back(move(board));
            return;
        }
        int avail = full_ & ~(cols | d1 | d2);
        while (avail) {
            int b    = avail & (-avail);        // lowest set bit
            avail   &= avail - 1;
            int col  = __builtin_ctz(b);
            queens_.push_back(col);
            bt(cols | b, (d1 | b) >> 1, (d2 | b) << 1);
            queens_.pop_back();
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        n_ = n;
        full_ = (1 << n) - 1;
        queens_.clear();
        result_.clear();
        bt(0, 0, 0);
        return result_;
    }
};
