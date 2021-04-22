
#include "common.h"

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        else if (n == 1) return x;
        else if (n < 0) {
            if (n == INT_MIN)
                return 1 / (myPow(x, -(n + 1)) * x);
            else return 1 / myPow(x, -n);
        } else {
            double tmp = myPow(x, n / 2);
            return n % 2 == 0 ? tmp * tmp : tmp * tmp * x;
        }
    }
};

int main() {
    Solution s;
}
