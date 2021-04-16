
#include "common.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it_dest = nums.begin(), it = nums.begin(), end = nums.end();
        while(it != end) {
            if (it + 1 == end || *(it + 1) != *it)
                *it_dest++ = *it;
            it++;
        }
        return it_dest - nums.begin();
    }
};