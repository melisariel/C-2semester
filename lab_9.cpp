// Разработать класс Money для работы с денежными суммами, которые должны быть представлены: знаком суммы, количеством рублей и количеством копеек.
// Класс должен содержать все необходимые конструкторы и деструктор. В классе должны быть перегружены операции: присваивания, сложения и вычитания денег, умножения и деления денег на действительное число, сравнения, операция ввода/вывода в поток.

#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

class Money {
private:
    long long totalKopecks;

    static long long roundToKopecks(double value) {
        return llround(value * 100.0);
    }

public:
    // Конструкторы
    Money() : totalKopecks(0) {}

    Money(bool negative, long long rubles, int kopecks) {
        if (kopecks < 0 || kopecks >= 100)
            throw invalid_argument("Error");
        totalKopecks = rubles * 100 + kopecks;
        if (negative)
            totalKopecks = -totalKopecks;
    }

    Money(long long rubles, int kopecks) {
        if (kopecks < 0 || kopecks >= 100)
            throw invalid_argument("Error");
        totalKopecks = rubles * 100 + kopecks;
    }

    // Присваивание
    Money& operator=(const Money& other) {
        if (this != &other)
            totalKopecks = other.totalKopecks;
        return *this;
    }

    // Сложение
    Money operator+(const Money& other) const {
        Money result;
        result.totalKopecks = totalKopecks + other.totalKopecks;
        return result;
    }

    // Вычитание
    Money operator-(const Money& other) const {
        Money result;
        result.totalKopecks = totalKopecks - other.totalKopecks;
        return result;
    }

    // Умножение на число
    Money operator*(double value) const {
        Money result;
        result.totalKopecks = roundToKopecks((double)totalKopecks / 100.0 * value);
        return result;
    }

    // Деление на число
    Money operator/(double value) const {
        if (value == 0)
            throw runtime_error("Error");
        Money result;
        result.totalKopecks = roundToKopecks((double)totalKopecks / 100.0 / value);
        return result;
    }

    // Сравнение
    bool operator==(const Money& other) const {
        return totalKopecks == other.totalKopecks;
    }

    bool operator!=(const Money& other) const {
        return !(*this == other);
    }

    bool operator<(const Money& other) const {
        return totalKopecks < other.totalKopecks;
    }

    bool operator>(const Money& other) const {
        return totalKopecks > other.totalKopecks;
    }

    bool operator<=(const Money& other) const {
        return totalKopecks <= other.totalKopecks;
    }

    bool operator>=(const Money& other) const {
        return totalKopecks >= other.totalKopecks;
    }

    // Ввод
    friend istream& operator>>(istream& in, Money& m) {
        long long rubles;
        int kopecks;
        char sign;

        in >> sign >> rubles >> kopecks;

        if (kopecks < 0 || kopecks >= 100)
            throw invalid_argument("Error");

        m.totalKopecks = rubles * 100 + kopecks;
        if (sign == '-')
            m.totalKopecks = -m.totalKopecks;

        return in;
    }

    // Вывод
    friend ostream& operator<<(ostream& out, const Money& m) {
        long long absValue = llabs(m.totalKopecks);
        long long rubles = absValue / 100;
        int kopecks = absValue % 100;

        if (m.totalKopecks < 0)
            out << "-";
        else
            out << "+";

        out << rubles << " rub " 
            << (kopecks < 10 ? "0" : "") << kopecks << " cop";

        return out;
    }
};