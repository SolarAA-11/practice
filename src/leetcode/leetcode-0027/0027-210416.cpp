
#include "common.h"

class Solution {
private:
    int solve1(vector<int>& nums, int val) {
        auto it_dest = nums.begin(), it = nums.begin(), end = nums.end();
        while(it != end) {
            if (*it != val)
                *it_dest++ = *it;
            it++;
        }
        return it_dest - nums.begin();
    }
    int solve2(vector<int>& nums, int val) {
        auto it = nums.begin();
        auto rit = nums.rbegin();
        while(it != rit.base()) {
            if (*it == val)
                swap(*it, *rit++);
            else it++;
        }
        return it - nums.begin();
    }
public:
    int removeElement(vector<int>& nums, int val) {
        return solve2(nums, val);
    }
};