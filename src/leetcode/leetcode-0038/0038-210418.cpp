
#include "common.h"

class Solution {
public:
    string countAndSay(int n) {
        string  result = "1";
        auto f = [](const string& s) ->string {
            stringstream os;
            auto it = s.begin(), begin = s.begin(), end = s.end();
            size_t count = 0;
            while(it != end) {
                if (it == begin || *it != *(it - 1)) {
                    if (it != begin)
                        os << count << *(it - 1);
                    count = 1;
                } else count++;
                it++;
            }
            os << count << *(it - 1);
            return os.str();
        };
        for (int i = 2; i <= n; ++i) {
            result = f(result);
        }
        return result;
    }
};

int main() {
    Solution s;
}
