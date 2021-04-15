
#include "common.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        vector<long long> super_nums(nums.begin(), nums.end());
        int len = super_nums.size();
        for (int i = 0; i < len; ++i) {
            if (i != 0 && super_nums[i - 1] == super_nums[i])
                continue;

            for (int j = i + 1; j < len; ++j) {
                if (j - 1 != i && super_nums[j - 1] == super_nums[j])
                    continue;

                int k = j + 1, q = len - 1;
                long long sum;
                while(k < q) {
                    if (k - 1 != j && super_nums[k - 1] == super_nums[k]) {
                        k++;continue;
                    }
                    if (q + 1 != len && super_nums[q + 1] == super_nums[q]) {
                        q--;continue;
                    }

                    sum = super_nums[i] + super_nums[j] + super_nums[k] + super_nums[q];
                    if (sum < target) ++k;
                    else if (sum > target) --q;
                    else {
                        ans.push_back({static_cast<int>(super_nums[i]) , static_cast<int>(super_nums[j]) , static_cast<int>(super_nums[k]) , static_cast<int>(super_nums[q])});
                        ++k, --q;
                    }
                }
            }
        }

        return ans;
    }
};