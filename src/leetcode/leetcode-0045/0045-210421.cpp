
#include "common.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        int cur_max_index = 0, index = 0, next_max_step = 0, step = 0;
        for (step = 0;cur_max_index < nums.size() - 1; cur_max_index = next_max_step, ++step) {
            while (index <= cur_max_index) {
                next_max_step = max(next_max_step, index + nums[index]);
                index++;
            }
        }
        return step;
    }
};

int main() {
    Solution s;
}
