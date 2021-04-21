
#include "common.h"

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> bucket;
    void dfs(int pos, int target, vector<int>& nums) {
        if (target == 0) ans.push_back(bucket);
        else if (pos >= nums.size() || nums[pos] > target) return;
        else {
            int p1 = lower_bound(nums.begin(), nums.end(), nums[pos]) - nums.begin();
            int c = count(bucket.begin(), bucket.end(), nums[pos]);
            if (pos - p1 == c) {
                bucket.push_back(nums[pos]);
                dfs(pos + 1, target - nums[pos], nums);
                bucket.pop_back();
            }
            dfs(pos + 1, target, nums);
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0,target,candidates);
        return move(ans);
    }
};

int main() {
    Solution s;
}
