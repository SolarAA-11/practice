
#include "common.h"

class Solution {
public:
    double myPow(double x, int n) {
        if (n == INT_MIN) return (1 / x) * myPow(x, n + 1);
        else if (n < 0) return 1 / myPow(x, -n);
        else if (n == 0) return 1;
        else if (n == 1) return x;
        else {
            double temp = myPow(x, n >> 1);
            return temp * temp * (n & 1 ? x : 1);
        }
    }
};

int main() {
    Solution s;
}
