class Solution {
    public:
        string crackSafe(int n, int k) {
            if (n == 1) {
                string s;
                for (int i = 0; i < k; i++) s += ('0' + i);
                return s;
            }
    
            int total = 1;
            for (int i = 0; i < n; i++) total *= k;   // k^n edges
            int highK = total / k;                      // k^(n-1) nodes
    
            vector<bool> visited(total, false);
            string result;
            result.reserve(total + n);  // pre-allocate
    
            // Iterative DFS with explicit stack to avoid stack overflow
            struct Frame { int node; int d; };
            vector<Frame> stk;
            stk.push_back({0, 0});
    
            while (!stk.empty()) {
                auto& [node, d] = stk.back();
                if (d < k) {
                    int edge = node * k + d;
                    d++;                        // advance for next iteration
                    if (!visited[edge]) {
                        visited[edge] = true;
                        stk.push_back({edge % highK, 0});
                    }
                } else {
                    stk.pop_back();
                    if (!stk.empty()) {
                        // post-order: append the digit that led here
                        result += char('0' + (stk.back().d - 1));
                    }
                }
            }
    
            result.append(n - 1, '0');  // append starting node
            reverse(result.begin(), result.end());
            return result;
        }
    };