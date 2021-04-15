//
// Created by SolarDomo on 2021/4/14.
//

#include "common.h"

class Solution {
public:
    using it = vector<int>::iterator;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        unsigned count = nums1.size() + nums2.size();
        return count % 2 != 0 ?
               findKThElementValue(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), count / 2 + 1) :
               (
                       findKThElementValue(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), count / 2) +
                       findKThElementValue(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), count / 2 + 1)
               ) / 2.0;
    }
    int findKThElementValue(const it& begin_it_1, unsigned size_1,
                               const it& begin_it_2, unsigned size_2,
                                unsigned k) {
        if (size_1 == 0) return *(begin_it_2 + k - 1);
        else if (size_2 == 0) return *(begin_it_1 + k - 1);
        else if (k == 1) return min(*begin_it_1, *begin_it_2);

        auto it1 = size_1 > k / 2 ? begin_it_1 + k / 2 - 1: begin_it_1 + size_1 - 1;
        auto it2 = size_2 > k / 2 ? begin_it_2 + k / 2 - 1: begin_it_2 + size_2 - 1;

        if (*it1 < *it2) return findKThElementValue(it1 + 1, size_1 - (it1 - begin_it_1 + 1), begin_it_2, size_2, k - (it1 - begin_it_1 + 1));
        else return findKThElementValue(begin_it_1, size_1, it2 + 1, size_2 - (it2 - begin_it_2 + 1), k - (it2 - begin_it_2 + 1));
    }
};

int main() {
    Solution s;
    vector<int> v1{1,3}, v2 {2};
    auto a = s.findMedianSortedArrays(v1, v2);
    cout << a ;
}