
#include "common.h"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int, int> counter;
        for (int i : candidates) counter[i]++;
        vector<int> temp;
        dfs(counter.begin(), counter.end(), target, temp);
        return ans;
    }

private:
    using map_it = map<int,int>::iterator;
    vector<vector<int>> ans;
    void dfs(const map_it it, const map_it end, int sum, vector<int>& nums) {
        if (sum == 0) ans.emplace_back(nums);
        else if (it != end && sum >= it->first) {
            auto next_it = next(it);
            for (int i = 0; i <= it->second && it->first * i <= sum; ++i) {
                dfs(next_it, end, sum - i * it->first, nums);
                nums.push_back(it->first);
            }
            while (!nums.empty() && nums.back() == it->first)
                nums.pop_back();
        }
    }
};

int main() {
    Solution s;
}
