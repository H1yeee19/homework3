/*
 * Homework 3 — main.cpp
 * 이 파일은 수정하지 마세요.
 * problem1.cpp ~ problem4.cpp 에 있는 TODO 함수만 구현하세요.
 *
 * 실행: ./hw3_main Test/case1.txt
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct Record {
    string label;
    int    count;
    double rate;
};

struct Student {
    int id;
    int score;
};

// ── Forward declarations: problem1.cpp ────────────────────────
void addViaRef(int& r, int delta);
int  sumByConstRef(const int& a, const int& b);
void swapByRef(int& a, int& b);
void incrementByRef(int& r);
void incrementByPtr(int* p);

// ── Forward declarations: problem2.cpp ────────────────────────
int  doubleByValue(int n);
void doubleByPointer(int* p);
void doubleByRef(int& n);
void updateRecord(Record& r, int newCount, double newRate);
void printRecord(const Record& r);

// ── Forward declarations: problem3.cpp ────────────────────────
void describe(int x);
void describe(double x);
int& elementAt(int* arr, int n, int i);

// ── Forward declarations: problem4.cpp ────────────────────────
void     updateScore(Student& student, int newScore);
bool     isPassed(const Student& student, int passingScore);
void     printStudent(const Student& student);
Student& findTopScorer(Student* students, int n);

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
    const int MAX_N   = 50;
    const int ARR_LEN = 5;

    // Problem 1
    int p1a, p1b, p1delta;
    fin >> p1a >> p1b >> p1delta;

    // Problem 2
    int    p2n;
    fin >> p2n;
    Record rec;
    int    newCount;
    double newRate;
    fin >> rec.label >> rec.count >> rec.rate >> newCount >> newRate;

    // Problem 3
    int    p3int;
    double p3dbl;
    fin >> p3int >> p3dbl;
    int p3arr[ARR_LEN];
    for (int i = 0; i < ARR_LEN; i++) fin >> p3arr[i];
    int p3idx, p3newval;
    fin >> p3idx >> p3newval;

    // Problem 4
    int ns; fin >> ns;
    Student students[MAX_N];
    for (int i = 0; i < ns; i++) fin >> students[i].id >> students[i].score;
    int passingScore, updateIdx, newScore;
    fin >> passingScore >> updateIdx >> newScore;
    fin.close();

    // ══ Problem 1: Reference ══════════════════════════════════
    cout << "=== Problem 1: Reference ===" << "\n";
    {
        cout << "[Part 1] Reference as alias" << "\n";
        int val = p1a;
        int& ref = val;
        cout << "val = " << val << "\n";
        cout << "ref = " << ref << "\n";
        cout << "Same address: " << (&val == &ref ? "true" : "false") << "\n";
        addViaRef(ref, p1delta);
        cout << "After addViaRef(ref, " << p1delta << "): val = " << val << "\n";

        cout << "[Part 2] const reference" << "\n";
        cout << "sumByConstRef(" << p1a << ", " << p1b << ") = "
             << sumByConstRef(p1a, p1b) << "\n";
        const int& cr = val;
        cout << "const ref of val: " << cr << "\n";
        cout << "Same address as val: " << (&val == &cr ? "true" : "false") << "\n";

        cout << "[Part 3] swap by reference" << "\n";
        int a = p1a, b = p1b;
        cout << "Before: a = " << a << ", b = " << b << "\n";
        swapByRef(a, b);
        cout << "After swapByRef: a = " << a << ", b = " << b << "\n";

        cout << "[Part 4] Reference vs Pointer" << "\n";
        int n = p1b;
        cout << "n = " << n << "\n";
        incrementByRef(n);
        cout << "After incrementByRef(n): n = " << n << "\n";
        incrementByPtr(&n);
        cout << "After incrementByPtr(&n): n = " << n << "\n";
    }

    // ══ Problem 2: Parameter Passing ══════════════════════════
    cout << "=== Problem 2: Parameter Passing ===" << "\n";
    cout << fixed << setprecision(2);
    {
        cout << "[Part 1] Pass by value" << "\n";
        int n = p2n;
        cout << "n = " << n << "\n";
        cout << "doubleByValue(n) = " << doubleByValue(n) << "\n";
        cout << "n after call: " << n << "\n";

        cout << "[Part 2] Pass by pointer" << "\n";
        n = p2n;
        cout << "Before: n = " << n << "\n";
        doubleByPointer(&n);
        cout << "After doubleByPointer(&n): n = " << n << "\n";

        cout << "[Part 3] Pass by reference" << "\n";
        n = p2n;
        cout << "Before: n = " << n << "\n";
        doubleByRef(n);
        cout << "After doubleByRef(n): n = " << n << "\n";

        cout << "[Part 4] Struct by reference" << "\n";
        cout << "Before: " << rec.label << " " << rec.count << " " << rec.rate << "\n";
        updateRecord(rec, newCount, newRate);
        cout << "After: " << rec.label << " " << rec.count << " " << rec.rate << "\n";

        cout << "[Part 5] Const reference" << "\n";
        printRecord(rec);
    }

    // ══ Problem 3: Function Overloading ═══════════════════════
    cout << "=== Problem 3: Function Overloading ===" << "\n";
    {
        cout << "[Part 1] Overloading — describe" << "\n";
        describe(p3int);
        describe(p3dbl);

        cout << "[Part 2] Return by reference" << "\n";
        cout << "arr:";
        for (int i = 0; i < ARR_LEN; i++) cout << " " << p3arr[i];
        cout << "\n";
        cout << "elementAt(arr, " << ARR_LEN << ", " << p3idx << ") = "
             << elementAt(p3arr, ARR_LEN, p3idx) << "\n";
        elementAt(p3arr, ARR_LEN, p3idx) = p3newval;
        cout << "After elementAt(arr, " << ARR_LEN << ", " << p3idx << ") = "
             << p3newval << ": arr[" << p3idx << "] = " << p3arr[p3idx] << "\n";
    }

    // ══ Problem 4: Integrated ════════════════════════════════
    cout << "=== Problem 4: Integrated ===" << "\n";
    {
        cout << "[Part 1] Print students" << "\n";
        for (int i = 0; i < ns; i++) printStudent(students[i]);

        cout << "[Part 2] isPassed (passing score = " << passingScore << ")" << "\n";
        for (int i = 0; i < ns; i++)
            cout << students[i].id << ": "
                 << (isPassed(students[i], passingScore) ? "passed" : "failed") << "\n";

        cout << "[Part 3] Update score" << "\n";
        cout << "Before: "; printStudent(students[updateIdx]);
        updateScore(students[updateIdx], newScore);
        cout << "After: "; printStudent(students[updateIdx]);

        cout << "[Part 4] Top scorer" << "\n";
        Student& top = findTopScorer(students, ns);
        printStudent(top);
    }

    return 0;
}
