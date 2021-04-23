
#include "common.h"

const pair<int, string> roman_number[13]{
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"},
};


class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        auto it = s.begin();
        while (it != s.end()) {
            for (const auto &item : roman_number) {
                if (equal(item.second.begin(), item.second.end(), it)) {
                    result += item.first;
                    it += item.second.size();
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
}
