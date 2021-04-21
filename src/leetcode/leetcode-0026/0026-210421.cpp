
#include "common.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it1 = nums.begin(), it2 = nums.begin();
        while (it2 != nums.end()) {
            if (it2 == nums.begin() || *it2 != *(it2 - 1))
                *it1++ = *it2;
            it2++;
        }
        return it1 - nums.begin();
    }
};

int main() {
    Solution s;
}
