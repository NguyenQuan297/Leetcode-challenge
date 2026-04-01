#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // Backtracking with row / column / 3x3 box occupancy sets
        rows.assign(9, {});
        cols.assign(9, {});
        boxes.assign(9, {});
        pb = &board;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    char c = board[i][j];
                    rows[i].insert(c);
                    cols[j].insert(c);
                    boxes[(i / 3) * 3 + (j / 3)].insert(c);
                }
            }
        }
        dfs();
    }

private:
    vector<vector<char>>* pb;
    vector<unordered_set<char>> rows, cols, boxes;

    bool dfs() {
        auto& board = *pb;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    continue;
                }
                int b = (i / 3) * 3 + (j / 3);
                for (char d = '1'; d <= '9'; ++d) {
                    if (rows[i].count(d) || cols[j].count(d) || boxes[b].count(d)) {
                        continue;
                    }
                    board[i][j] = d;
                    rows[i].insert(d);
                    cols[j].insert(d);
                    boxes[b].insert(d);
                    if (dfs()) {
                        return true;
                    }
                    board[i][j] = '.';
                    rows[i].erase(d);
                    cols[j].erase(d);
                    boxes[b].erase(d);
                }
                return false;
            }
        }
        return true;
    }
};
