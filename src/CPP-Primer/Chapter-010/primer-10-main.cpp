//
// Created by SolarDomo on 2021/4/15.
//

int main() {
    int local_val = 10;
    const int const_local_val = 100;
    auto f = [&] {
        local_val = 1000;
        const_local_val = 50;
    };
}