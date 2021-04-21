
#include "common.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto it = nums.rbegin() + 1;
        while (it != nums.rend() && *it >= *(it - 1)) it++;
        if (it != nums.rend())
            swap(*it, *find_if(nums.rbegin(), it, [&](int v) {return v > *it;}));
        reverse(nums.rbegin(), it);
    }
};

int main() {
    Solution s;
}
