
#include "common.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        auto it1 = nums.begin(), it2 = it1, it_end = nums.end();
        auto it3 = nums.rbegin();
        while(it1 != it_end) {
            if (it1 != nums.begin() && *it1 == *(it1 - 1)) {
                it1++; continue;
            }
            int target = 0 - *it1;
            it2 = it1 + 1;
            if (it2 == it_end) break;
            it3 = nums.rbegin();
            while (it2 + 1 != it3.base()) {
                if (it2 != it1 + 1 && *it2 == *(it2 - 1)) {
                    it2++; continue;
                }
                if (it3 != nums.rbegin() && *it3 == *(it3 - 1)) {
                    it3++; continue;
                }

                int sum = *it2 + *it3;
                if (sum == target) result.push_back({*it1, *it2, *it3});
                if (sum < target) it2++;
                else it3++;
            }
            it1++;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> v = {-1,0,1,2,-1,-4};
    auto it = v.rbegin().base();
    auto it2 = v.begin() + 6;
    cout << (it == it2) << endl;
    s.threeSum(v);
}
