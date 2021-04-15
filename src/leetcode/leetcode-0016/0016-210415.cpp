
#include "common.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = accumulate(nums.begin(), nums.begin() + 3, 0),
            len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (i != 0 && nums[i - 1] == nums[i])
                continue;
            int j = i + 1, k = len - 1, sum;
            while(j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < abs(ans - target)) {
                    ans = sum;
                    if (ans == target) break;
                }
                if (sum < target) j++;
                else k--;
            }
        }
        return ans;
    }
};