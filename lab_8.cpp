// Составить описание класса для представления времени.
// Предусмотреть возможности установки времени и изменения его отдельных полей (час, минута, секунда) с проверкой допустимости вводимых значений.
// В случае недопустимых значений полей выбрасываются исключения. Создать методы изменения времени на заданное количество часов, минут и секунд.

#include <iostream>
#include <stdexcept>

using namespace std;

class Time {
private:
    int totalSeconds;
    static const int SECONDS_IN_DAY = 24 * 60 * 60;

    static void validate(int h, int m, int s) {
        if (h < 0 || h > 23)
            throw invalid_argument("Invalid hours");
        if (m < 0 || m > 59)
            throw invalid_argument("Invalid minutes");
        if (s < 0 || s > 59)
            throw invalid_argument("Invalid seconds");
    }

    void normalize() {
        totalSeconds %= SECONDS_IN_DAY;
        if (totalSeconds < 0)
            totalSeconds += SECONDS_IN_DAY;
    }

public:
    Time(int h = 0, int m = 0, int s = 0) {
        setTime(h, m, s);
    }

    void setTime(int h, int m, int s) {
        validate(h, m, s);
        totalSeconds = h * 3600 + m * 60 + s;
    }

    void setHours(int h) {
        validate(h, getMinutes(), getSeconds());
        setTime(h, getMinutes(), getSeconds());
    }

    void setMinutes(int m) {
        validate(getHours(), m, getSeconds());
        setTime(getHours(), m, getSeconds());
    }

    void setSeconds(int s) {
        validate(getHours(), getMinutes(), s);
        setTime(getHours(), getMinutes(), s);
    }

    void addHours(int h) {
        totalSeconds += h * 3600;
        normalize();
    }

    void addMinutes(int m) {
        totalSeconds += m * 60;
        normalize();
    }

    void addSeconds(int s) {
        totalSeconds += s;
        normalize();
    }

    int getHours() const {
        return totalSeconds / 3600;
    }

    int getMinutes() const {
        return (totalSeconds % 3600) / 60;
    }

    int getSeconds() const {
        return totalSeconds % 60;
    }

    void print() const {
        cout << (getHours() < 10 ? "0" : "") << getHours() << ":"
             << (getMinutes() < 10 ? "0" : "") << getMinutes() << ":"
             << (getSeconds() < 10 ? "0" : "") << getSeconds() << "\n";
    }
};

int main() {
    try {
        Time t(23, 50, 40);
        t.print();

        t.addMinutes(30);
        t.print();

        t.setSeconds(70);
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";
    }
}