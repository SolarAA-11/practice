
#include "common.h"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_set<vector<int>> result;
        int count = 1;
        for (int i = 0; i < nums.size(); ++i)
            count = count * (i + 1);
        for (int i = 0; i < count; ++i) {
            result.insert(nums);
            next_prem(nums);
        }
        return {result.begin(), result.end()};
    }

private:
    void next_prem(vector<int>& nums) {
        if (nums.empty()) return;
        auto it = nums.rbegin() + 1, end_it = nums.rend();
        while (it != end_it && *it >= *(it - 1)) it++;
        if (it != end_it) {
            auto it2 = find_if(nums.rbegin(), it, [&](int val) { return val > *it;});
            swap(*it, *it2);
        }
        reverse(nums.rbegin(), it);
    }
};

int main() {
    Solution s;
}
