//
// Created by SolarDomo on 2021/4/18.
//

#include "common.h"

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        auto it = costs.begin();
        size_t result = 0;
        while(it != costs.end() && *it <= coins) {
            result++, coins -= *it++;
        }
        return result;
    }
};

int main() {

}