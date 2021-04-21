
#include "common.h"

class Solution {
private:
    bool f(vector<int>& nums) {
        auto it = nums.rbegin();
        while(it != nums.rend() && (it == nums.rbegin() || *it > *(it - 1)))
            it++;
        if (it != nums.rend()) {
            swap(*it, *find_if(nums.rbegin(), nums.rend(), [&](int val){return val > *it;}));
        } else return true;
        reverse(nums.rbegin(), it);
        return false;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans{nums};
        while(!f(nums)) ans.emplace_back(nums);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v{1,2,3};
    s.permute(v);
}
