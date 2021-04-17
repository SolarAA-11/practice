
#include "common.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto func = bind(Solution::search, nums, target, placeholders::_1);
        int lower = func(less<int>()),
            upper = func(less_equal<int>());
        if (lower == upper) return {-1,-1};
        else return {lower, upper - 1};
    }

private:
    static int search(vector<int>& nums, int target, const function<bool(int, int)>& compare) {
        size_t p1 = 0, p2 = nums.size();
        while(p1 < p2) {
            size_t mid = p1 + (p2 - p1) / 2;
            if (compare(nums[mid], target))
                p1 = mid + 1;
            else p2 = mid;
        }
        return p1;
    }
};

int main() {
    Solution s;
}
