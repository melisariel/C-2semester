// Алгоритм сортировки вставками с бинарным поиском, Сортировка перемешиванием или шейкерная сортировка, Четно-нечетная сортировка.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;

class Timer {
    using clock_t = chrono::high_resolution_clock;
    chrono::time_point<clock_t> start;
public:
    Timer() { start = clock_t::now(); }
    void reset() { start = clock_t::now(); }
    double elapsed() const {
        return chrono::duration<double>(clock_t::now() - start).count();
    }
};

void fillRandom(vector<int>& a, int min, int max) {
    for (size_t i = 0; i < a.size(); ++i)
        a[i] = rand() % (max - min + 1) + min;
}

// Вставки с бинарным поиском
void binaryInsertion(vector<int>& a) {
    for (size_t i = 1; i < a.size(); ++i) {
        int key = a[i];
        size_t l = 0, r = i;

        while (l < r) {
            size_t m = (l + r) / 2;
            if (a[m] <= key) l = m + 1;
            else r = m;
        }

        for (size_t j = i; j > l; --j)
            a[j] = a[j - 1];

        a[l] = key;
    }
}

// Шейкерная
void shaker(vector<int>& a) {
    size_t left = 0, right = a.size() - 1;
    while (left < right) {
        for (size_t i = left; i < right; ++i)
            if (a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        --right;

        for (size_t i = right; i > left; --i)
            if (a[i] < a[i - 1])
                swap(a[i], a[i - 1]);
        ++left;
    }
}

// Четно-нечетная
void oddEven(vector<int>& a) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;

        for (size_t i = 1; i + 1 < a.size(); i += 2)
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                sorted = false;
            }

        for (size_t i = 0; i + 1 < a.size(); i += 2)
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                sorted = false;
            }
    }
}

double test(void (*sortFunc)(vector<int>&), size_t n) {
    vector<int> a(n);
    fillRandom(a, 1, 100000);
    Timer t;
    sortFunc(a);
    return t.elapsed();
}

int main() {
    srand(time(0));

    vector<size_t> sizes = {10000, 50000, 100000};

    cout << left << setw(18) << "Algorithm";
    for (auto n : sizes) cout << setw(12) << n;
    cout << "(sec)\n";

    cout << left << setw(18) << "Binary Insertion";
    for (auto n : sizes) cout << setw(12) << test(binaryInsertion, n);
    cout << "\n";

    cout << left << setw(18) << "Shaker";
    for (auto n : sizes) cout << setw(12) << test(shaker, n);
    cout << "\n";

    cout << left << setw(18) << "Odd-Even";
    for (auto n : sizes) cout << setw(12) << test(oddEven, n);
    cout << "\n";
}