
#include "common.h"



int main() {
    allocator<string> alloc1, alloc2;
    allocator<int> alloc3;
    auto p1 = alloc1.allocate(10);
    alloc3.deallocate(reinterpret_cast<int *>(p1), 10);
    cout << "OK" << endl;
}
