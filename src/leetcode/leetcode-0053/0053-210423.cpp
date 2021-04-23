
#include "common.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int s1 = 0, s2 = 0;
        auto it = nums.begin();
        while (it != nums.end()) {
            s2 += *it;
            ans = max(ans, s2 - s1);
            s1 = min(s1, s2);
            it++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(v);
}
