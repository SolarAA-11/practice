//
// Created by SolarDomo on 2021/4/14.
//

#include "common.h"

class Solution {
private:
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

public:
    string intToRoman(int num) {
        string result;
        for(const auto& p: roman_number) {
            while(p.first <= num) {
                num -= p.first;
                result += p.second;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    auto str = s.intToRoman(20);
    cout << str;
}