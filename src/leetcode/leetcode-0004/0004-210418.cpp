
#include "common.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t len = nums1.size() + nums2.size();
        auto func = [&](size_t k) {
            return find_k(0, nums1, 0, nums2, k);
        };
        return len % 2 != 0 ? func(len / 2 + 1) : (func(len / 2) + func(len / 2 + 1)) / 2.0;
    }

private:
    int find_k(int pos1, vector<int>& nums1, int pos2, vector<int>& nums2, size_t k) {
        if (pos1 == nums1.size()) return nums2[pos2 + k - 1];
        else if (pos2 == nums2.size()) return nums1[pos1 + k - 1];
        else if (k == 1) return min(nums1[pos1], nums2[pos2]);
        else {
            int mid1 = pos1 + k / 2 - 1, mid2 = pos2 + k / 2 - 1;
            if (mid1 >= nums1.size()) mid1 = nums1.size() - 1;
            if (mid2 >= nums2.size()) mid2 = nums2.size() - 1;
            if (nums1[mid1] < nums2[mid2]) return find_k(mid1 + 1, nums1, pos2, nums2, k - (mid1 + 1 - pos1));
            else return find_k(pos1, nums1, mid2 + 1, nums2, k - (mid2 + 1 - pos2));
        }
    }
};

int main() {
    Solution s;
    vector<int> v1{1,3}, v2{2};
    s.findMedianSortedArrays(v1,v2);
    vector<int> v{1,2,3};
    size_t p1 = 3;
    size_t p2 = v.size() - p1 - 1;
    cout << p2;
}
