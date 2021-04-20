
#include "common.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t len = nums1.size() + nums2.size();
        auto func = bind(&Solution::find_k,
                         this,
                         nums1.begin(), nums1.end(),
                         nums2.begin(), nums2.end(),
                         placeholders::_1);
        if (len % 2 == 0) return (*func(len / 2) + *func(len / 2 + 1)) / 2.0;
        else return *func(len / 2 + 1);
    }

private:
    using it = vector<int>::iterator;
    it find_k(it it1, it it2, it it3, it it4, int k) {
        if (it1 == it2) return it3 + k - 1;
        else if (it3 == it4) return it1 + k - 1;
        else {
            if (k == 1) return *it1 < *it3 ? it1 : it3;
            auto mid1 = it1 + k / 2 - (k >= 2), mid2 = it3 + k / 2 - (k >= 2);
            if (mid1 >= it2) mid1 = it2 - 1;
            if (mid2 >= it4) mid2 = it4 - 1;
            if (*mid1 < *mid2) return find_k(mid1 + 1, it2, it3, it4, k - (mid1 + 1 - it1));
            else return find_k(it1, it2, mid2 + 1, it4, k - (mid2 + 1 - it3));
        }
    }
};

int main() {
    Solution s;
    vector<int> v1{1,3}, v2{2};
    cout << s.findMedianSortedArrays(v1, v2);
}
