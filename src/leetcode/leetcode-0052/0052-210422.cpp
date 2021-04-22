
#include "common.h"

class Solution {
private:
    int c,x1,x2, ans, len;
    void dfs(int x, int n) {
        if (n == 0) ans++;
        else if (x == len) return;
        else {
            for (int y = 0; y < len; ++y) {
                int p2 = 1 << y,
                    p3 = 1 << (x + y),
                    p4 = 1 << (len + x - y);
                if (!(c & p2 ||
                      x1 & p3 ||
                      x2 & p4
                )) {
                    c |= p2; x1 |= p3; x2 |= p4;
                    dfs(x + 1,n - 1);
                    c ^= p2; x1 ^= p3; x2 ^= p4;
                }
            }
        }
    }
public:
    int totalNQueens(int n) {
        dfs(0,len = n);
        return ans;
    }
};

int main() {
    Solution s;
}
