
#include "common.h"

class Solution {
private:
    using it = vector<int>::iterator;
    it  find_k(it st1, it ed1, it st2, it ed2, int k) {
        if (st1 == ed1) return st2 + k - 1;
        else if (st2 == ed2) return st1 + k - 1;
        else {
            if (k == 1) return *st1 < *st2 ? st1 : st2;

            auto mid1 = st1 + (k / 2) - 1, mid2 = st2 + (k / 2) - 1;
            if (mid1 >= ed1) mid1 = ed1 - 1;
            if (mid2 >= ed2) mid2 = ed2 - 1;
            if (*mid1 < *mid2)
                return find_k(mid1 + 1, ed1,st2,ed2,k - (mid1 + 1 - st1));
            else
                return find_k(st1,ed1,mid2 + 1,ed2,k - (mid2 + 1 - st2));
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto len = nums1.size() + nums2.size();
        auto f = bind(&Solution::find_k, this,
                      nums1.begin(), nums1.end(),
                      nums2.begin(), nums2.end(),
                      placeholders::_1);
        if (len & 1) return *f(len / 2 + 1);
        else return (*f(len / 2) + *f(len / 2 + 1)) / 2.0;
    }
};

int main() {
    Solution s;
}
