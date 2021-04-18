//
// Created by SolarDomo on 2021/4/18.
//

#include "common.h"

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> c_set(sentence.begin(), sentence.end());
        return c_set.size() == 26;
    }
};

int main() {

}

