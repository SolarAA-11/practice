//
// Created by SolarDomo on 2021/4/14.
//

#include "common.h"

class Solution {
public:
    auto num2pair(int val) {
        deque<int> result;
        int temp_val = val;
        while(temp_val != 0) {
            result.push_front(abs(temp_val % 10));
            temp_val /= 10;
        }
        return make_pair(result, val > 0);
    }

    auto pair2num(const pair<deque<int>, bool>& p) {
        int val = 0;
        for(int v: p.first)
            val = val * 10 + v * (p.second ? 1 : -1);
        return val;
    }

    bool p1_less_equal_p2(const pair<deque<int>, bool>& p1, const pair<deque<int>, bool>& p2) {
        if (p1.second && p2.second)
            return p1.first.size() < p2.first.size() ||
                    p1.first.size() == p2.first.size() && p1.first <= p2.first;
        else if (!p1.second && !p2.second)
            return p1.first.size() > p2.first.size() ||
                    p1.first.size() == p2.first.size() && p1.first >= p2.first;
        else
            return !p1.second && p2.second;
    }

    int reverse(int x) {
        if (x == 0) return 0;

        auto max_int_pair = num2pair(INT_MAX);
        auto min_int_pair = num2pair(INT_MIN);
        auto x_int_pair = num2pair(x);

        std::reverse(x_int_pair.first.begin(), x_int_pair.first.end());
        while(x_int_pair.first.front() == 0)
            x_int_pair.first.pop_front();

        if (x_int_pair.second) {
            if (p1_less_equal_p2(x_int_pair, max_int_pair))
                return pair2num(x_int_pair);
            else return 0;
        } else {
            if (p1_less_equal_p2(min_int_pair, x_int_pair))
                return pair2num(x_int_pair);
            else return 0;
        }
    }
};

int main() {
    Solution s;
    s.reverse(-2147483412);
}