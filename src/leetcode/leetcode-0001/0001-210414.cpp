//
// Created by SolarDomo on 2021/4/14.
//

#include "common.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int count = nums.size();
        for(int i = 0;i < count;++i) {
            int remainder = target - nums[i];
            for(int j = i + 1;j < count;++j) {
                if (nums[j] == remainder) {
                    return {i, j};
                }
            }
        }
        return {0,0};
    }
};
