
#include "common.h"

class Solution {
private:
    vector<int> nums, bucket;
    vector<vector<int>> result;
    void f(int pos, int target) {
        if (target == 0) result.emplace_back(bucket);
        else if (pos < nums.size() && nums[pos] <= target) {
            int i;
            for (i = 0; i * nums[pos] <= target; ++i) {
                f(pos + 1, target - nums[pos] * i);
                bucket.push_back(nums[pos]);
            }
            bucket.erase(bucket.end() - i, bucket.end());
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        nums = move(candidates);
        sort(nums.begin(),nums.end());
        f(0,target);
        return result;
    }
};

int main() {
    Solution s;
}
