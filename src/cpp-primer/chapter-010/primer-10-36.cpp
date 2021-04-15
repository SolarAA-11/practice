
#include "common.h"

int main() {
    list<int> li{1,2,3,4,5,0,6,7};
    auto it = find(li.rbegin(), li.rend(), 0);
    if (it != li.rend())
        cout << *it << endl;
}
