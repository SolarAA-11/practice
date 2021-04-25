//
// Created by SolarAA on 2021/4/25.
//

#include "common.h"

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        if (restrictions.empty()) return n - 1;
        int ans = 0;
        sort(restrictions.begin(), restrictions.end(), [](vector<int>& vec1, vector<int>& vec2){
            return vec1[1] < vec2[1];
        });
        map<int, int> fixed_position;
        fixed_position[1] = 0;
        for (const auto &restrict_height : restrictions) {
            auto next_it = fixed_position.lower_bound(restrict_height[0]);
            auto prev_it = prev(next_it);
            if (next_it == fixed_position.end()) {
                int dist_prev = restrict_height[0] - prev_it->first;
                int prev_decided_height = prev_it->second + dist_prev;
                fixed_position[restrict_height[0]] = min(restrict_height[1], prev_decided_height);
            } else {
                int dist_prev = restrict_height[0] - prev_it->first;
                int prev_decided_height = prev_it->second + dist_prev;
                int dist_next = next_it->first - restrict_height[0];
                int next_decided_height = next_it->second + dist_next;
                fixed_position[restrict_height[0]] =
                        min(restrict_height[1], min(prev_decided_height,next_decided_height));
            }
            ans = max(ans, fixed_position[restrict_height[0]]);
        }
        auto it = fixed_position.begin();
        while(next(it) != fixed_position.end()) {
            auto next_it = next(it);
            int distance = next_it->first - it->first - 1;
            int diff = abs(next_it->second - it->second);
            int h = (distance - diff + 1) / 2;
            h += max(it->second, next_it->second);
            ans = max(ans, h);
            it = next_it;
        }
        it = prev(fixed_position.end());
        ans = max(ans, it->second + n - it->first);
        return ans;
    }
};

int main() {
    priority_queue<int> pq;
    pq.push(0);
    pq.push(3);
    pq.push(4);
    pq.push(1);
    while(!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
}