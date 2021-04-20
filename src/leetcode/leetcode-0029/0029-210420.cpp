
#include "common.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        else if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        else if (dividend == INT_MIN && divisor == 1) return INT_MIN;

        bool positive = true;
        if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0) {
            if (dividend > 0) dividend = -dividend;
            if (divisor > 0) divisor = -divisor;
            positive = false;
        } else if (dividend > 0 && divisor > 0)
            dividend = -dividend, divisor = -divisor;

        int result = 0;
        int figure, product;
        while (dividend <= divisor) {
            figure = 1, product = divisor;
            while (dividend - product <= product) {
                figure += figure, product += product;
            }
            result += figure;
            dividend -= product;
        }
        return positive ? result : -result;
    }
};

int main() {
    Solution s;
    s.divide(INT_MIN, 1);
}
