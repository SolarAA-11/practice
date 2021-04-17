
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
        int result = 0, pos = 0;
        size_t len = s.size(), st = 0;
        while(st != len) {
            auto pos_find = s.find(roman_number[pos].second, st);
            if (pos_find == st) {
                result += roman_number[pos].first;
                st += roman_number[pos].second.size();
            } else pos++;
        }
        return result;
    }
};

int main() {
    Solution s;
}
