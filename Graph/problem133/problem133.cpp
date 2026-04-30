#include <unordered_map>
#include <vector>

using namespace std;


#ifndef ONLINE_JUDGE
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0) {}
    Node(int v) : val(v) {}
    Node(int v, vector<Node*> nb) : val(v), neighbors(nb) {}
};
#endif

class Solution {
    unordered_map<Node*, Node*> visited;

    Node* dfs(Node* node) {
        if (!node) {
            return nullptr;
        }
        auto it = visited.find(node);
        if (it != visited.end()) {
            return it->second;
        }
        Node* clone = new Node(node->val);
        visited[node] = clone;
        for (Node* nb : node->neighbors) {
            clone->neighbors.push_back(dfs(nb));
        }
        return clone;
    }

public:
    Node* cloneGraph(Node* node) {
        visited.clear();
        return dfs(node);
    }
};
