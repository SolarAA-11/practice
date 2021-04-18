//
// Created by SolarDomo on 2021/4/18.
//

#include "common.h"

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int result = 0;
        for (int index_post = 0; index_post < 32; ++index_post) {
            int x = 1 << index_post;
            int a1_count = 0, a2_count = 0;
            for (int i = 0; i < arr1.size(); ++i) {
                a1_count += (arr1[i] >> index_post) & 1;
            }
            for (int j = 0; j < arr2.size(); ++j) {
                a2_count += (arr2[j] >> index_post) & 1;
            }
            if (a1_count % 2 == 1 && a2_count % 2 == 1)
                result += 1 << index_post;
        }
        return result;
    }
};

int main() {

}