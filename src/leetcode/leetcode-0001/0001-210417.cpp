
#include "common.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> p;
        p.reserve(nums.size());
        for (int i = 0; i < nums.size(); ++i)
            p.emplace_back(nums[i], i);
        sort(p.begin(), p.end());
        size_t p1 = 0, p2 = p.size() - 1;
        while(p1 != p2) {
            int sum = p[p1].first + p[p2].first;
            if (sum == target) return {p[p1].second, p[p2].second};
            else if (sum < target) p1++;
            else p2--;
        }
        return {0,0};
    }
};

int main() {
    Solution s;
    vector<int> v = {2,7,11,15};
    s.twoSum(v,9);
}
