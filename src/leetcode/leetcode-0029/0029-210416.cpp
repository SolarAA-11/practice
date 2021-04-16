
#include "common.h"

class Solution {
private:
    using LL = long long;
    LL  div(LL x, LL y) {
        if (x == 0) return 0;
        else if (x < 0 || y < 0) {
            if (x < 0 && y < 0) return div(-x,-y);
            else if (x < 0) return -div(-x,y);
            else return -div(x,-y);
        } else {
            if (x < y) return 0;
            else if (x == y) return 1;
            else {
                LL  sum = y, add = 1;
                while(sum + sum <= x)
                    sum = sum + sum, add = add + add;
                return add + div(x - sum, y);
            }
        }
    }
public:
    int divide(int dividend, int divisor) {
        LL result = div(dividend, divisor);
        return result >= INT_MIN && result <= INT_MAX ? (int)result : INT_MAX;
    }
};

int main() {
    Solution s;
    s.divide(INT_MIN, 1);
}