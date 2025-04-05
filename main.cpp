#include <iostream>

void test();

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    std::string to_string() {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

    bool operator==(Fraction &other) {
        return this->numerator == other.numerator &&
               this->denominator == other.denominator;
    }
};

Fraction reduce(Fraction input) {
    int divider = 2;
    while (divider <= input.numerator && divider <= input.denominator) {
        if (input.numerator % divider == 0 &&
            input.denominator % divider == 0) {
            input.numerator /= divider;
            input.denominator /= divider;
            continue;
            }
        divider++;
    }
    return input;
}

int main() {
    test();
}

void test() {
    // Reduce given fraction to minimum
    // 2/4 -> 1/2
    Fraction inputs[4] = {Fraction(1, 2),
                          Fraction(2, 4),  // FIXED: Changed `{}` to `()`
                          Fraction(4, 2),
                          Fraction(6, 8)};

    Fraction outputs[4] = {Fraction(1, 2),
                           Fraction(1, 2),  // FIXED: Changed `{}` to `()`
                           Fraction(2, 1),
                           Fraction(3, 4)};

    for (int i = 0; i < 4; ++i) {
        Fraction input = inputs[i];
        Fraction expect = outputs[i];

        Fraction actual = reduce(input);

        if (expect == actual) {
            std::cout << "PASS!" << std::endl;
        } else {
            std::cout << "FAIL! case is: " << input.to_string() << std::endl;
        }
    }
}
