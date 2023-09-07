#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Fraction {
    size_t numerator;

    size_t denominator;

public:
    /* v Конструктор по умолчанию */
    Fraction(size_t numerator_, size_t denominator_) {
        numerator = numerator_;
        denominator = denominator_;
    }

    /* v Конструктор копирования */
    Fraction (const Fraction &other) {
        numerator = other.numerator;
        denominator = other.denominator;
    }

    /* v Перегруженный оператор присваивания */
    Fraction& operator=(const Fraction &other) {
        if (this == &other)
            return *this;
        numerator = other.numerator;
        denominator = other.denominator;
        return *this;
    }

    friend Fraction operator+(const Fraction& a, const Fraction& b);

    friend std::ostream& operator<<(std::ostream &os, const Fraction &frac);
};

/* v Перегруженный оператор вывода */
std::ostream& operator<<(std::ostream &os, const Fraction &frac) {
    os << frac.numerator << '/' << frac.denominator;
    return os;
}

/* v Перегруженный оператор сложения */
Fraction operator+(const Fraction& a, const Fraction& b) {
    if (a.denominator == b.denominator) {
        return Fraction(a.numerator + b.numerator, a.denominator);
    } else {
        size_t num, den;
        den = a.denominator * b.denominator;
        num = a.numerator * b.denominator + b.numerator * a.denominator;
        return Fraction(num, den);
    }
}

Fraction frac4(0, 0);

int main ()
{
    Fraction frac1(3, 5);
    Fraction frac2(2, 5);
    Fraction frac5(0, 0);

    /* v Тут сначала будет вызван перегруженный оператор сложения, а затем конструктор копирования */
    Fraction frac3 = frac1 + frac2;
    std::cout << frac3 << std::endl;

    /* v Тут будет вызван перегруженный оператор сложения, конструктор копирования, оператор присваивания, конструктор копирования */
    frac4 = frac2 + frac3;
    std::cout << frac4 << std::endl;

    frac5 = frac3;
    std::cout << frac5 << std::endl;

    return 0;
}
