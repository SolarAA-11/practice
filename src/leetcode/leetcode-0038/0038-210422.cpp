
#include "common.h"

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        else {
            string s = countAndSay(n - 1);
            s.push_back('#');
            stringstream os;
            auto it = s.begin();
            int count = 0;
            while (it != s.end()) {
                if (it != s.begin() && *it != *(it - 1)) {
                    os << count << *(it - 1);
                    count = 1;
                } else count++;
                it++;
            }
            return move(os.str());
        }
    }
};

int main() {
    Solution s;
}
