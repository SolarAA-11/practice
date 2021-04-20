
#include "common.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        int cur_step_max_index = 0, step = 0, index = 0;
        while(cur_step_max_index < nums.size() - 1) {
            int next_step_max_index = 0;
            while(index < nums.size() && index <= cur_step_max_index) {
                next_step_max_index = max(next_step_max_index, index + nums[index]);
                index++;
            }
            cur_step_max_index = next_step_max_index;
            step++;
        }
        return step;
    }
};

int main() {
    Solution s;
}
