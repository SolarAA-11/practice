
#include "common.h"

class Solution {
private:
    using it = vector<int>::iterator;
    it find_k(it st1, it end1, it st2, it end2, int k) {
        if (st1 == end1) return st2 + k - 1;
        else if (st2 == end2) return st1 + k - 1;
        else {
            if (k == 1) return *st1 < *st2 ? st1 : st2;

            auto mid1 = st1 + k / 2 - 1, mid2 = st2 + k / 2 - 1;
            if (mid1 >= end1) mid1 = end1 - 1;
            if (mid2 >= end2) mid2 = end2 - 1;
            if (*mid1 < *mid2)
                return find_k(mid1 + 1, end1, st2, end2, k - (mid1 + 1 - st1));
            else
                return find_k(st1, end1, mid2 + 1, end2, k - (mid2 + 1 - st2));
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto len = nums1.size() + nums2.size();
        auto f = bind(&Solution::find_k, this, nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), placeholders::_1);
        if (len % 2 == 0)
            return (*f(len / 2) + *f(len / 2 + 1)) / 2.0;
        else return *f(len / 2 + 1);
    }
};

int main() {
    Solution s;
    vector<int> v1{1,3}, v2{2};
    cout << s.findMedianSortedArrays(v1,v2);
}
