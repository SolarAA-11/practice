//
// Created by SolarDomo on 2021/4/14.
//

#include "common.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int p1 = 0,
            p2 = height.size(),
            ans = 0;
        while(p1 < p2) {
            ans = max(ans, min(height[p1], height[p2 - 1]) * (p2 - p1 - 1));
            if (height[p1] > height[p2 - 1]) p2--;
            else p1++;
        }
        return ans;
    }
};

int main() {

}