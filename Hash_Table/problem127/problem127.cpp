#include <deque>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) {
            return 0;
        }

        deque<pair<string, int>> q;
        q.emplace_back(beginWord, 1);

        while (!q.empty()) {
            auto cur = q.front().first;
            const int d = q.front().second;
            q.pop_front();
            if (cur == endWord) {
                return d;
            }
            for (int i = 0; i < static_cast<int>(cur.size()); ++i) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == cur[i]) {
                        continue;
                    }
                    string nw = cur;
                    nw[i] = c;
                    if (words.count(nw)) {
                        words.erase(nw);
                        q.emplace_back(std::move(nw), d + 1);
                    }
                }
            }
        }
        return 0;
    }
};
