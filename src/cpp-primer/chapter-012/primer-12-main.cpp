
#include "common.h"

class StrBlob {
public:
    typedef vector<string>::size_type size_type;
    StrBlob():data(make_shared<vector<string>>()) {}
    StrBlob(initializer_list<string> li) :
        data (make_shared<vector<string>>(li)) {}
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string& str) { data->push_back(str); }
    void pop_back();
    string& front() ;
    const string& front()const;
    string& back();
    const string& back()const;

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string& msg) const;
};

string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

const string &StrBlob::front() const {
    check(0, "front on empty StrBlob.");
    return data->front();
}

string &StrBlob::back() {
    check(0, "back on empty StrBlob.");
    return data->front();
}

const string &StrBlob::back() const {
    check(0, "back on empty StrBlob.");
    return data->front();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob.");
    data->pop_back();
}

void StrBlob::check(StrBlob::size_type i, const string &msg) const {
    if (i >= data->size())
        throw out_of_range(msg);
}

unique_ptr<string> return_unique() {
    unique_ptr<string> p_str(new string("Hello"));
    unique_ptr<string> p_str_2 = p_str;

}


int main() {
    constexpr long long LEN = 1e8;
    try {
        int *parray = nullptr;
        long long total_len = 0;
        while(true) {
            parray = new (nothrow) int[LEN];
            if (parray != nullptr) {
                total_len += LEN;
                cout << "Succeed " << total_len << endl;
            }
            else cout << "I can't afford anymore than " << total_len << endl;
        }
    } catch (bad_alloc &e) {
        cout << "Oh you bad guy" << endl;
    }
}
