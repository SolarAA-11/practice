
#include "common.h"


map<string, vector<string>> m;

void add_new_family(const string& name) {
    if (m.find(name) != m.end()) {
        cout << "That family name has already existed." << endl;
        return;
    }
    m[name] = vector<string>();
}

void add_child_to_family(const string& name, const string& child) {
    if (m.find(name) == m.end()) {
        cout << "That family name does not exist." << endl;
        return;
    }
    m[name].emplace_back(child);
}

int main() {

}