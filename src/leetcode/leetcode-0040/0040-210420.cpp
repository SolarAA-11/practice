
#include "common.h"

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> board;
    void dfs(int pos, int target, vector<int>& nums) {
        if (target == 0) ans.push_back(board);
        else if (pos >= nums.size() || nums[pos] > target) return;
        else {
            int p1 = lower_bound(nums.begin(), nums.end(), nums[pos]) - nums.begin();
            int c = count(board.begin(), board.end(), nums[pos]);
            if (pos - p1 == c) {
                board.push_back(nums[pos]);
                dfs(pos + 1, target - nums[pos], nums);
                board.pop_back();
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
