//
// Created by SolarAA on 2021/4/25.
//

#include "common.h"

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long ret = 0, sum = 0;
        auto it1 = nums.begin(), it2 = nums.begin();
        while (it2 != nums.end()) {
            long long count = it2 - it1;
            if (count == 0) {
                count = 1;
                sum = *it2++;
            } else {
                while(count > 0 && count * *it2 - sum > k) {
                    sum -= *it1++;
                    count--;
                }
                sum += *it2++;
                count++;
            }
            ret = max(ret, count);
        }
        return ret;
    }
};

int main() {

}