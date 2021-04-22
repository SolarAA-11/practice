
#include "common.h"

class Solution {
public:
    int reverse(int x) {
        int min_div_10 = INT_MIN / 10;
        int max_div_10 = INT_MAX / 10;
        int result = 0;
        while (x) {
            if (result > 0 && result > max_div_10 || result == max_div_10 && x % 10 >= 7) {
                result = 0; break;
            }
            if (result < 0 && result < min_div_10 || result == min_div_10 && x % 10 <= -8) {
                result = 0; break;
            }
            result = result * 10 + x % 10;
            x /= 10;
        }
        return result;
    }
};

int main() {
    cout << INT_MIN << ":" << INT_MAX << endl;
    Solution s;
    cout << s.reverse(1534236469);
}
