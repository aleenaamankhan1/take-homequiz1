#include <iostream>

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int inputs[] = {1, 2, 3, 4, 5, 9, 11};
    bool expected[] = {false, true, true, false, true, false, true};

    for (int i = 0; i < 7; i++) {
        bool result = is_prime(inputs[i]);
        if (result == expected[i]) {
            std::cout << "PASS!" << std::endl;
        } else {
            std::cout << "FAIL!" << std::endl;
        }
    }

    return 0;
}