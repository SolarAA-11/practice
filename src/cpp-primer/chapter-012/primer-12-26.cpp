
#include "common.h"


int main() {
    int n = 10;
    allocator<string> alloc;
    auto const p = alloc.allocate(n);
    auto q = p;
    string s;
    while(cin >> s)
        alloc.construct(q++, s);
    const size_t size = q - p;
    // use the array
    while(q != p)
        alloc.destroy(--q);
    alloc.deallocate(p, n);
}