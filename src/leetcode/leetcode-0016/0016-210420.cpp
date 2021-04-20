
#include "common.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = accumulate(nums.begin(), nums.begin() + 3, 0);
        sort(nums.begin(), nums.end());
        auto it1 = nums.begin(), end_it = nums.end();
        while(it1 + 2 != end_it) {
            auto it2 = it1 + 1;
            auto it3 = nums.rbegin();
            while (it2 != it3.base() - 1) {
                int sum = *it1 + *it2 + *it3;
                if (abs(target - sum) < abs(target - result)) {
                    if (sum == target) return sum;
                    result = sum;
                }
                if (sum <= target) it2++;
                else it3++;
            }
            it1++;
        }
        return result;
    }
};

int main() {
    Solution s;
}
