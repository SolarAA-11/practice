
#include "common.h"

class Solution {
private:
    using it = vector<int>::iterator;
    it f(it st, it end, int target, const function<bool(int ,int)>& comp = less<int>()) {
        while(st != end) {
            auto mid = st + (end - st) / 2;
            if (comp(*mid, target))
                st = mid + 1;
            else end = mid;
        }
        return st;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it1 = f(nums.begin(), nums.end(), target),
        it2 = f(nums.begin(), nums.end(), target, less_equal<int>());
        if (it1 != it2) return {int(it1 - nums.begin()), int(it2 - nums.begin() - 1)};
        else return {-1,-1};
    }
};

int main() {
    Solution s;
}
