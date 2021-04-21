
#include "common.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        transform(num1.begin(), num1.end(), num1.begin(), [](char c){ return c - '0'; });
        transform(num2.begin(), num2.end(), num2.begin(), [](char c){ return c - '0'; });
        vector<int> result(num1.size() + num2.size() + 1, -1);

        auto it1 = num1.rbegin(), end1 = num1.rend();
        auto it2 = num2.rbegin(), end2 = num2.rend();
        auto it3 = result.begin();
        while (it2 != end2) {
            auto tit3 = it3;
            int product = 0, extra = 0;
            it1 = num1.rbegin();
            while (it1 != end1) {
                product = *it1 * *it2 + extra;
                if (product >= 10) {
                    extra = product / 10;
                    product %= 10;
                } else extra = 0;
                if (*tit3 == -1) *tit3 = 0;
                *tit3 += product;
                if (*tit3 >= 10) {
                    extra += *tit3 / 10;
                    *tit3 %= 10;
                }
                tit3++;
                it1++;
            }
            while (extra != 0) {
                if (*tit3 == -1) *tit3 = 0;
                *tit3 += extra;
                if (*tit3 >= 10) {
                    extra += *tit3 / 10;
                    *tit3 %= 10;
                } else extra = 0;
                tit3++;
            }
            it2++;
            it3++;
        }
        result.erase(find(result.begin(), result.end(), -1), result.end());
        reverse(result.begin(), result.end());
        string ret(result.size(), ' ');
        transform(result.begin(), result.end(), ret.begin(), [](int val){return val + '0';});
        return ret;
    }
};

int main() {
    Solution s;
}
