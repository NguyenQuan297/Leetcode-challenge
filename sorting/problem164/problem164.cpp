#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        vector<int> arr = nums;
        for (int shift = 0; shift < 32; shift += 8) {
            vector<vector<int>> buckets(256);
            for (int x : arr) {
                buckets[(x >> shift) & 0xFF].push_back(x);
            }
            arr.clear();
            for (auto& b : buckets) {
                arr.insert(arr.end(), b.begin(), b.end());
            }
        }
        int ans = 0;
        for (size_t i = 1; i < arr.size(); ++i) {
            ans = max(ans, arr[i] - arr[i - 1]);
        }
        return ans;
    }
};
