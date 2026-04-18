#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) {
            return {};
        }

        unordered_map<string, unordered_set<string>> parents;
        vector<string> layer = {beginWord};

        while (!layer.empty()) {
            bool found = false;
            for (const string& w : layer) {
                if (w == endWord) {
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
            for (const string& w : layer) {
                words.erase(w);
            }
            unordered_set<string> nextSet;
            for (const string& w : layer) {
                string nw = w;
                for (int i = 0; i < static_cast<int>(nw.size()); ++i) {
                    const char old = nw[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == old) {
                            continue;
                        }
                        nw[i] = c;
                        if (words.count(nw)) {
                            nextSet.insert(nw);
                            parents[nw].insert(w);
                        }
                    }
                    nw[i] = old;
                }
            }
            if (nextSet.empty()) {
                return {};
            }
            layer.assign(nextSet.begin(), nextSet.end());
        }

        vector<vector<string>> res;
        vector<string> path;
        dfs(endWord, beginWord, parents, path, res);
        return res;
    }

private:
    static void dfs(const string& w, const string& beginWord,
                    unordered_map<string, unordered_set<string>>& parents,
                    vector<string>& path, vector<vector<string>>& res) {
        path.push_back(w);
        if (w == beginWord) {
            res.push_back(vector<string>(path.rbegin(), path.rend()));
        } else {
            for (const string& p : parents[w]) {
                dfs(p, beginWord, parents, path, res);
            }
        }
        path.pop_back();
    }
};
