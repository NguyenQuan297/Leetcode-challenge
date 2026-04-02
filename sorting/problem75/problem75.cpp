#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // One-pass three-way partition: 0 | 1 | 2
        int low = 0, mid = 0, high = static_cast<int>(nums.size()) - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
