
#include "common.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        transform(num1.begin(), num1.end(), num1.begin(), [](char c){ return c - '0'; });
        transform(num2.begin(), num2.end(), num2.begin(), [](char c){ return c - '0'; });
        string result(num1.size() + num2.size() + 1, 23);
        auto it1 = num1.begin(), it2 = num2.begin(), it3 = result.begin();
        while (it2 != num2.end()) {
            auto it3_tmp = it3;
            it1 = num1.begin();
            int extra = 0;
            while (it1 != num1.end()) {
                int product = *it2 * *it1 + extra;
                if (product >= 10) {
                    extra = product / 10;
                    product %= 10;
                } else extra = 0;
                if (*it3_tmp == 23) *it3_tmp = 0;
                *it3_tmp += product;
                if (*it3_tmp >= 10) {
                    extra += *it3_tmp / 10;
                    *it3_tmp %= 10;
                }
                it3_tmp++;
                it1++;
            }
            while (extra != 0) {
                if (*it3_tmp == 23) *it3_tmp = 0;
                *it3_tmp += extra;
                if (*it3_tmp >= 10) {
                    extra = *it3_tmp / 10;
                    *it3_tmp %= 10;
                } else extra = 0;
                it3_tmp++;
            }
            it2++;
            it3++;
        }
        result.erase(result.begin() + result.find(char (23)), result.end());
        transform(result.begin(), result.end(), result.begin(), [](char c) { return c + '0'; });
        return result;
    }
};

int main() {
    Solution s;
    cout << s.multiply("123",
                       "456");
}
