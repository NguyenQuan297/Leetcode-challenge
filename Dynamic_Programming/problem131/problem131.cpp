#include <functional>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<string>> partition(string s) {
            int n = s.size();
    
            // Step 1: Precompute palindrome table — isPal[i][j] = true if s[i..j] is a palindrome
            vector<vector<bool>> isPal(n, vector<bool>(n, false));
            for (int i = n - 1; i >= 0; i--) {
                for (int j = i; j < n; j++) {
                    if (s[i] == s[j] && (j - i <= 2 || isPal[i + 1][j - 1])) {
                        isPal[i][j] = true;
                    }
                }
            }
    
            // Step 2: Backtrack with O(1) palindrome lookup
            vector<vector<string>> res;
            vector<string> path;
    
            function<void(int)> backtrack = [&](int start) {
                if (start == n) {
                    res.push_back(path);
                    return;
                }
                for (int end = start; end < n; end++) {
                    if (isPal[start][end]) {            // O(1) lookup
                        path.push_back(s.substr(start, end - start + 1));
                        backtrack(end + 1);
                        path.pop_back();
                    }
                }
            };
    
            backtrack(0);
            return res;
        }
    };