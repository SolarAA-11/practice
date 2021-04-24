
#include "common.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        auto it = nums.begin();
        while (it != nums.end()) {
            if (*it >= 1 && *it <= len && nums[*it - 1] != *it) {
                swap(nums[*it - 1], *it);
            } else it++;
        }
        for (int i = 0; i < len; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return len + 1;
    }
};

int main() {
    Solution s;
}
