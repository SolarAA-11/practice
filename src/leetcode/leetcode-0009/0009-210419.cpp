
#include "common.h"

class Solution {
public:
    bool isPalindrome(int x) {
        ostringstream os; os << x;
        string s = os.str();
        return equal(s.begin(), s.end(), s.rbegin());
    }
};

int main() {
    Solution s;
    s.isPalindrome(121);
}
