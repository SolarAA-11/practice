
#include "common.h"

class Solution {
private:
    map<int,int> counter;
    vector<vector<int>> result;
    vector<int> bucket;
    void f(int pos) {
        if (pos == bucket.size()) result.emplace_back(bucket);
        else {
            for (auto &item : counter) {
                if (item.second != 0) {
                    bucket[pos] = item.first;
                    item.second--;
                    f(pos + 1);
                    item.second++;
                }
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (const auto &item : nums) counter[item]++;
        bucket.assign(nums.size(),0);
        f(0);
        return result;
    }
};

int main() {
    Solution s;
}
