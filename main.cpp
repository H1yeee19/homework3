/*
 * Homework 2 — main.cpp
 * 이 파일은 수정하지 마세요.
 * problem1.cpp ~ problem4.cpp 에 있는 TODO 함수만 구현하세요.
 *
 * 실행: ./hw2_main Test/case1.txt
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct Product {
    string name;
    int    quantity;
    double price;
};

struct Student {
    string name;
    int    scores[3];
    double average;
};

// ── Forward declarations: problem1.cpp ────────────────────────
int    add(int a, int b);
int    divide(int a, int b);
double toDouble(int a, int b);

// ── Forward declarations: problem2.cpp ────────────────────────
int    findMostExpensive(Product products[], int n);
int    countAboveThreshold(Product products[], int n, int threshold);
double totalValue(Product products[], int n);
string priceCategory(double price);

// ── Forward declarations: problem3.cpp ────────────────────────
void   increment(int* p);
int*   findMax(int* arr, int n);
void   mySwap(int* a, int* b);

// ── Forward declarations: problem4.cpp ────────────────────────
void     computeAverage(Student* s);
Student* findTopStudent(Student* students, int n);
void     applyBonus(Student* students, int n, double threshold, int bonus);

// ─────────────────────────────────────────────────────────────
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <test_data_file>" << "\n";
        return 1;
    }
    ifstream fin(argv[1]);
    if (!fin) {
        cerr << "Cannot open: " << argv[1] << "\n";
        return 1;
    }

    // ── Read test data ────────────────────────────────────────
    const int MAX_N = 50;

    int np; fin >> np;
    Product products[MAX_N];
    for (int i = 0; i < np; i++)
        fin >> products[i].name >> products[i].quantity >> products[i].price;

    int countThreshold; fin >> countThreshold;

    int k; fin >> k;
    int arr[MAX_N];
    for (int i = 0; i < k; i++) fin >> arr[i];

    int ns; fin >> ns;
    Student students[MAX_N];
    for (int i = 0; i < ns; i++) {
        fin >> students[i].name
            >> students[i].scores[0]
            >> students[i].scores[1]
            >> students[i].scores[2];
        students[i].average = 0.0;
    }

    double bonusThreshold; int bonus;
    fin >> bonusThreshold >> bonus;
    fin.close();

    // ══ Problem 1: Type Arithmetic and auto ══════════════════
    cout << "=== Problem 1: Type Arithmetic and auto ===" << "\n";
    cout << fixed << setprecision(1);
    {
        cout << "[Part 1] auto type deduction" << "\n";
        auto x = 7 / 2;
        auto y = 7.0 / 2;
        auto z = static_cast<double>(7) / 2;
        cout << "7 / 2 = " << x << "\n";
        cout << "7.0 / 2 = " << y << "\n";
        cout << "(double)7 / 2 = " << z << "\n";

        cout << "[Part 2] Functions" << "\n";
        cout << "add(3, 4) = " << add(3, 4) << "\n";
        cout << "divide(7, 2) = " << divide(7, 2) << "\n";
        cout << "toDouble(7, 2) = " << toDouble(7, 2) << "\n";

        cout << "[Part 3] char arithmetic" << "\n";
        char c = 'A';
        auto asInt   = static_cast<int>(c);
        auto shifted = c + 32;
        cout << "'A' as int = " << asInt << "\n";
        cout << "'A' + 32 as int = " << shifted << "\n";
        cout << "(char)('A' + 32) = " << static_cast<char>(c + 32) << "\n";

        cout << "[Part 4] unsigned overflow" << "\n";
        unsigned char uc = 250;
        unsigned char result = static_cast<unsigned char>(uc + 10);
        cout << "(unsigned char)(250 + 10) = " << static_cast<int>(result) << "\n";
    }

    // ══ Problem 2: struct and Flow Control ═══════════════════
    cout << "=== Problem 2: struct and Flow Control ===" << "\n";
    cout << fixed << setprecision(2);
    {
        cout << "[Part 1] Most expensive product" << "\n";
        int idx = findMostExpensive(products, np);
        cout << "Name: " << products[idx].name << "\n";
        cout << "Price: " << products[idx].price << "\n";

        cout << "[Part 2] Products with quantity > " << countThreshold << "\n";
        cout << "Count: " << countAboveThreshold(products, np, countThreshold) << "\n";

        cout << "[Part 3] Total inventory value" << "\n";
        cout << "Total: " << totalValue(products, np) << "\n";

        cout << "[Part 4] Price category" << "\n";
        for (int i = 0; i < np; i++)
            cout << products[i].name << ": " << priceCategory(products[i].price) << "\n";
    }

    // ══ Problem 3: Pointer ════════════════════════════════════
    cout << "=== Problem 3: Pointer ===" << "\n";
    {
        cout << "[Part 1] Address and dereference" << "\n";
        int val = 42;
        int* ptr = &val;
        cout << "val = " << val << "\n";
        cout << "*ptr = " << *ptr << "\n";
        *ptr = 100;
        cout << "After *ptr = 100, val = " << val << "\n";

        cout << "[Part 2] increment" << "\n";
        int x = 10;
        increment(&x);
        cout << "After increment, x = " << x << "\n";
        increment(&x);
        cout << "After 2nd increment, x = " << x << "\n";

        cout << "[Part 3] findMax" << "\n";
        int* maxPtr = findMax(arr, k);
        if (maxPtr != nullptr) {
            cout << "Max value = " << *maxPtr << "\n";
            cout << "Max index = " << (maxPtr - arr) << "\n";
        } else {
            cout << "Not found" << "\n";
        }

        cout << "[Part 4] mySwap" << "\n";
        int a = 5, b = 8;
        cout << "Before: a = " << a << ", b = " << b << "\n";
        mySwap(&a, &b);
        cout << "After: a = " << a << ", b = " << b << "\n";

        cout << "[Part 5] nullptr" << "\n";
        int* nullPtr = nullptr;
        if (nullPtr == nullptr)
            cout << "Pointer is null" << "\n";
        else
            cout << "Pointer is not null" << "\n";
        nullPtr = &val;
        if (nullPtr == nullptr)
            cout << "Pointer is null" << "\n";
        else
            cout << "Pointer is not null" << "\n";
    }

    // ══ Problem 4: Integrated ═════════════════════════════════
    cout << "=== Problem 4: Integrated ===" << "\n";
    cout << fixed << setprecision(2);
    {
        cout << "[Part 1] Compute averages" << "\n";
        for (int i = 0; i < ns; i++) {
            computeAverage(&students[i]);
            cout << students[i].name << ": " << students[i].average << "\n";
        }

        cout << "[Part 2] Top student" << "\n";
        Student* top = findTopStudent(students, ns);
        if (top != nullptr) {
            cout << "Name: " << top->name << "\n";
            cout << "Average: " << top->average << "\n";
        }

        cout << "[Part 3] After bonus (threshold=" << (int)bonusThreshold
             << ", bonus=" << bonus << ")" << "\n";
        applyBonus(students, ns, bonusThreshold, bonus);
        for (int i = 0; i < ns; i++) {
            computeAverage(&students[i]);
            cout << students[i].name << ": " << students[i].average << "\n";
        }

        cout << "[Part 4] Direct modification via pointer" << "\n";
        Student* sptr = &students[0];
        sptr->scores[0] = 100;
        computeAverage(sptr);
        cout << sptr->name << " new average: " << sptr->average << "\n";
    }

    return 0;
}
