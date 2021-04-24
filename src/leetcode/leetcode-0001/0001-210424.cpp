
#include "common.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index_array(nums.size(), 0);
        for (int i = 0; i < index_array.size(); ++i)
            index_array[i] = i;
        sort(index_array.begin(), index_array.end(), [&](int i1, int i2) { return nums[i1] < nums[i2]; });
        int l = 0, r = nums.size() - 1, sum = 0;
        while (l < r) {
            sum = nums[index_array[l]] + nums[index_array[r]];
            if (sum == target)
                return {index_array[l], index_array[r]};
            else if (sum < target)
                l++;
            else r--;
        }
        return {-1, -1};
    }
};


int main() {
    Solution s;
}
