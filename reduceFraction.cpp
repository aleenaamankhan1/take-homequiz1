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
    int var = 19;
    int* p_var = &var;

    double num = 1.55;
    double* p_num = &num;

    (*p_num)++;  // Increment the double value

    // Corrected initialization with zeroed values for the dynamic array
    int* array = new int[20]();
    for (int i = 0; i < 20; i++) {
        array[i] = i + 1;
    }

    for (int i = 0; i < 20; i++) {
        std::cout << array[i] << std::endl;
    }


    int* xyz = array + 3;  // Pointer to element at index 3 of the array
    float sum = 0;
    for (int i = 0; i < 17; ++i) {  // Corrected: Loop within the valid range
        sum += xyz[i];
    }
    std::cout << "average is " << sum / 17 << std::endl;
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
