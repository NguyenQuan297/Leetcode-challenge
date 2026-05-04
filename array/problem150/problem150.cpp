#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;

        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                if (token == "+")       st.push(a + b);
                else if (token == "-")  st.push(a - b);
                else if (token == "*")  st.push(a * b);
                else                    st.push(a / b);  // C++ int division truncates toward zero
            } else {
                st.push(stoll(token));
            }
        }

        return static_cast<int>(st.top());
    }
};
