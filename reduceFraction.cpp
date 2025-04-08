#include <iostream>
#include <string>

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

void reduce(Fraction *input) {
    int divider = 2;
    while (divider <= input->numerator && divider <= input->denominator) {
        if (input->numerator % divider == 0 &&
            input->denominator % divider == 0) {
            input->numerator /= divider;
            input->denominator /= divider;
            continue;
        }
        divider++;
    }
}

int main() {

    int var = 55;
    int &game = var;
    std::cout << &game << std::endl;
    std::cout << &var << std::endl;
}

void test() {
    // Reduce given fraction to minimum
    Fraction inputs[4] = {Fraction(1, 2),
                          Fraction(2, 4),
                          Fraction(4, 2),
                          Fraction(6, 8)};
    Fraction outputs[4] = {Fraction(1, 2),
                           Fraction(1, 2),
                           Fraction(2, 1),
                           Fraction(3, 4)};

    for (int i = 0; i < 4; ++i) {
        Fraction input = inputs[i];
        Fraction expect = outputs[i];

        reduce(&input);

        if (expect == input) {
            std::cout << "PASS!" << std::endl;
        } else {
            std::cout << "FAIL! case is: " << input.to_string() << std::endl;
        }
    }
}
