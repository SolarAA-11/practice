
#include "common.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        size_t p1 = 0, p2 = height.size() - 1;
        unsigned result = 0;
        while(p1 < p2) {
            unsigned cur_capability = min(height[p1], height[p2]) * (p2 - p1);
            result = max(result, cur_capability);
            if (height[p1] < height[p2]) p1++;
            else p2--;
        }
        return result;
    }
};

int main() {
    Solution s;
}
