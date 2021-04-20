
#include "common.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it1 = nums.begin(), it2 = nums.end();
        while(it1 < it2) {
            auto mid = it1 + (it2 - it1) / 2;
            if (*mid >= target) it2 = mid;
            else it1 = mid + 1;
        }
        return it1 - nums.begin();
    }
};

int main() {
    Solution s;
}
