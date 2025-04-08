#include <iostream>

bool is_power_of_2(int num) {
    if (num <= 0) return false;
    if (num == 1) return true;

    if (num % 2 == 0) {
        return is_power_of_2(num / 2);
    }

    return false;
}
/*
int main() {
    int inputs[] = {1, 2, 3, 4, 5, 8, 16, 18, 32, 0, -2};
    bool expected[] = {true, true, false, true, false, true, true, false, true, false, false};

    for (int i = 0; i < 11; i++) {
        bool result = is_power_of_2(inputs[i]);
        if (result == expected[i]) {
            std::cout << "PASS!" << std::endl;
        } else {
            std::cout << "FAIL!" << std::endl;
        }
    }

    return 0;
}
/*