
#include "common.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        vector<int> result(num1.size() + num2.size() + 1, 0);
        transform(num1.begin(), num1.end(), num1.begin(), [](char c) {return c - '0';});
        transform(num2.begin(), num2.end(), num2.begin(), [](char c) {return c - '0';});
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        auto l1 = num1.size(), l2 = num2.size();
        for (int i = 0; i < l1; ++i) {
            for (int j = 0; j < l2; ++j) {
                result[i + j] += num1[i] * num2[j];
            }
        }
        int extra = 0;
        for (int i = 0; i < result.size(); ++i) {
            result[i] += extra;
            if (result[i] >= 10) {
                extra = result[i] / 10;
                result[i] %= 10;
            } else extra = 0;
        }
        auto it = find_if(result.rbegin(), result.rend(), [](char c){return c != 0;});
        result.erase(it.base(), result.end());
        string  ret(result.size(), ' ');
        transform(result.begin(), result.end(), ret.begin(), [](char c){return c + '0';});
        reverse(ret.begin(), ret.end());
        return move(ret);
    }
};

int main() {
    Solution s;
    cout << s.multiply("999", "999");
}
