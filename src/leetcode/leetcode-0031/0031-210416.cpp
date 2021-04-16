
#include "common.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) return;
        auto rit = nums.rbegin() + 1, rend = nums.rend();
        while(rit != rend && *rit >= *(rit - 1))
            rit++;
        if (rit != rend) {
            auto rit_find = find_if(nums.rbegin(), rit, [&](int val){
                return val > *rit;
            });
            swap(*rit, *rit_find);
        }
        reverse(nums.rbegin(), rit);
    }
};

int main() {
    Solution s;
    vector<int> nums = {
            3,2,1
    };
    s.nextPermutation(nums);
}