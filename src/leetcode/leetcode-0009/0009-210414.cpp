//
// Created by SolarDomo on 2021/4/14.
//

#include "common.h"

class Solution {
public:
    bool isPalindrome(int x) {
        ostringstream os;
        os << x;
        auto str = os.str();
        return equal(str.begin(), str.end(), str.rbegin());
    }
};

int main() {

}