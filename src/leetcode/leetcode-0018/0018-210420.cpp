
#include "common.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        auto it1 = nums.begin(), end_it = nums.end();
        while (it1 != end_it) {
            if (it1 != nums.begin() && *it1 == *(it1 - 1)) {
                it1++; continue;
            }

            auto it2 = it1 + 1;
            while (it2 != end_it) {
                if (it2 != it1 + 1 && *it2 == *(it2 - 1)) {
                    it2++;continue;
                }

                int goal = target - *it1 - *it2;
                auto it3 = it2 + 1;
                if (it3 == nums.end()) break;
                auto it4 = nums.rbegin();
                while (it3 != it4.base() - 1) {
                    if (it3 != it2 + 1 && *it3 == *(it3 - 1)) {
                        it3++;continue;
                    }
                    if (it4 != nums.rbegin() && *it4 == *(it4 - 1)) {
                        it4++; continue;
                    }

                    int sum = *it3 + *it4;
                    if (sum == goal) result.push_back({*it1, *it2, *it3, *it4});
                    if (sum < goal) it3++;
                    else it4++;
                }
                it2++;
            }
            it1++;
        }
        return result;
    }
};

int main() {
    Solution s;
}
