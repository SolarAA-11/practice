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
    int romanToInt(string s) {
        int ans = 0;
        s.push_back('#');
        auto it = s.begin();
        while(*it != '#') {
            for(const auto& num: roman_number) {
                if (equal(num.second.begin(), num.second.end(), it)) {
                    ans += num.first;
                    it += num.second.size();
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    int n = s.romanToInt("MCMXCIV");
    cout << n;
}