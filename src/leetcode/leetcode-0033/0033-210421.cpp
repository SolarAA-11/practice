
#include "common.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it1 = nums.begin(), it2 = nums.end();
        while(it1 != it2) {
            auto mid = it1 + (it2 - it1) / 2;
            if (*mid == target) return mid - nums.begin();
            else if (*it1 < *mid) {
                if (*it1 <= target && target <= *mid)
                    it2 = mid;
                else it1 = mid + 1;
            } else {
                if (*(it2 - 1) >= target && target >= *mid)
                    it1 = mid + 1;
                else it2 = mid;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
}
