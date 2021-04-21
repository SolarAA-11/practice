
#include "common.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto it1 = nums.begin(), it2 = nums.begin();
        while (it2 != nums.end()) {
            if (*it2 != val) *it1++ = *it2;
            it2++;
        }
        return it1 - nums.begin();
    }
};

int main() {
    Solution s;
}
