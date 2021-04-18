
#include "common.h"


struct destination {};
struct connection {};
connection connect(destination* dest) { return connection{}; }
void disconnect(connection conn) {cout << "Disconnected" << endl;}
void f(destination &d, bool excep) {
    auto conn = connect(&d);
    auto deleter_conn = [](connection* p_conn){
        disconnect(*p_conn);
    };
    unique_ptr<connection, decltype(deleter_conn)> p_conn(&conn, deleter_conn);
    if (excep)
        throw exception("Needed");
    cout << "Before exiting f" << endl;
}

int main() {
    destination dest;
    try {
        f(dest, true);
    } catch (exception& e) {
        cout << e.what() << endl;
    }

}