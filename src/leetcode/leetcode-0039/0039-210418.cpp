
#include "common.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        dfs(candidates.begin(), candidates.end(), target, tmp);
        return ans;
    }

private:
    vector<vector<int>> ans;
    void dfs(vector<int>::iterator it, const vector<int>::iterator end, int sum, vector<int>& nums) {
        if (sum == 0) ans.emplace_back(nums);
        else if (it != end && sum >= *it) {
            dfs(it + 1, end, sum, nums);
            int push_counter = 0;
            while((push_counter + 1) * *it <= sum) {
                push_counter++;
                nums.push_back(*it);
                dfs(it + 1, end, sum - push_counter * *it, nums);
            }
            while (push_counter--) nums.pop_back();
        }
    }
};

int main() {
    Solution s;
}
