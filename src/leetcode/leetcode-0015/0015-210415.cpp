
#include "common.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int p1 = 0; p1 < len; ++p1) {
            if (p1 != 0 && nums[p1] == nums[p1 - 1]) continue;

            int p2 = p1 + 1, p3 = len - 1;
            while(p2 < p3) {
                if (p2 - 1 != p1 && nums[p2 - 1] == nums[p2]) {
                    p2++;continue;
                }
                if (p3 + 1 != len && nums[p3 + 1] == nums[p3]) {
                    p3--;continue;
                }

                int cur_sum = nums[p1] + nums[p2] + nums[p3];
                if (cur_sum == 0)
                    result.push_back({nums[p1], nums[p2++], nums[p3--]});
                else if (cur_sum > 0)
                    p3--;
                else
                    p2++;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> a{-1, 0, 1, 2, -1, -4};
    solution.threeSum(a);
}