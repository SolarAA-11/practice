
#include "common.h"

pair<int, string> roman_number[13]{
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
    string intToRoman(int num) {
        size_t pos = 0;
        string  result;
        while(num != 0) {
            if (roman_number[pos].first <= num)
                num -= roman_number[pos].first, result += roman_number[pos].second;
            else pos++;
        }
        return result;
    }
};

int main() {
    Solution s;
}
