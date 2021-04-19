
#include "common.h"

char* concatenate_literal_string(const char* str1, const char* str2) {
    auto len1 = strlen(str1), len2 = strlen(str2);
    auto new_str = new char[len1 + len2 + 1]();
    copy(str1, str1 + len1, new_str);
    copy(str2, str2 + len2, new_str + len1);
    return new_str;
}

char* concatenate_string(const string& s1, const string& s2) {
    auto new_str = new char[s1.size() + s2.size() + 1];
    copy(s1.begin(), s1.end(), new_str);
    copy(s2.begin(), s2.end(), new_str + s1.size());
    return new_str;
}

int main() {

}
