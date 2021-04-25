//
// Created by SolarAA on 2021/4/25.
//

#include "common.h"

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        map<char, char> next = {
                {'a','e'},
                {'e','i'},
                {'i', 'o'},
                {'o', 'u'},
                {'u',' '},
        };
        int ret = 0, count = 0;
        for (int i = 0; i < word.size(); ++i) {
            if (count == 0 && word[i] == 'a') {
                count = 1;
            } else if (count != 0) {
                if (word[i] != word[i - 1]) {
                    if (word[i] == next[word[i - 1]])
                        count++;
                    else {
                        if (word[i - 1] == 'u')
                            ret = max(ret, count);
                        count = word[i] == 'a' ? 1 : 0;
                    }
                } else count++;
            }
        }
        if (count != 0 && word.back() == 'u')
            ret = max(ret, count);
        return ret;
    }
};

int main() {

}