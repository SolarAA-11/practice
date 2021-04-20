
#include "common.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1[0] == '0' || num2[0] == '0') return "0";

        vector<int> n1,n2;
        transform(num1.begin(), num1.end(), back_inserter(n1), [](char c) {return c - '0';});
        transform(num2.begin(), num2.end(), back_inserter(n2), [](char c) { return c - '0'; });
        reverse(n1.begin(), n1.end());
        reverse(n2.begin(), n2.end());

        vector<int> result(300, -1);
        auto it2 = n2.begin(),it_res = result.begin();
        while (it2 != n2.end()) {
            int extra = 0, product = 0;
            auto it1 = n1.begin(), it_res_add = it_res;
            while(it1 != n1.end()) {
                product = *it1 * *it2 + extra;
                if (product >= 10) {
                    extra = product / 10;
                    product %= 10;
                } else extra = 0;
                if (*it_res_add == -1) *it_res_add = 0;
                *it_res_add += product;
                if (*it_res_add >= 10) *it_res_add -= 10, extra++;
                it_res_add++;
                it1++;
            }
            if (extra > 0)
                *it_res_add = extra;
            it2++, it_res++;
        }

        string  result_str;
        auto res_end = find(result.begin(), result.end(), -1);
        transform(result.begin(), res_end, back_inserter(result_str), [](int i) { return char(i + '0'); });
        reverse(result_str.begin(), result_str.end());
        return result_str;
    }
};

int main() {
    Solution s;
    cout << s.multiply("9", "9");
}
