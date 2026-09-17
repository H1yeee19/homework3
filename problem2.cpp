/*
 * Problem 2: Parameter Passing
 *
 * 학번:
 * 이름:
 *
 * ─────────────────────────────────────────────────────────────
 * 아래 다섯 함수를 완성하세요.
 *
 *  doubleByValue(n)                   : n 의 2배를 계산합니다. (pass by value)
 *  doubleByPointer(p)                 : *p 를 2배로 만듭니다. (pass by pointer)
 *  doubleByRef(n)                     : n 을 2배로 만듭니다. (pass by reference)
 *  updateRecord(r, newCount, newRate) : r 의 count, rate 필드를 갱신합니다.
 *  printRecord(r)                     : r 의 label, count, rate 를 출력합니다.
 * ─────────────────────────────────────────────────────────────
 */
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Record {
    string label;
    int    count;
    double rate;
};

// n 의 2배를 반환합니다. (pass by value)
//   n      : 정수 복사본
//   반환값 : n * 2
int doubleByValue(int n) {
    // TODO
    return 0;
}

// *p 를 2배로 만듭니다. (pass by pointer)
//   p : 수정할 정수를 가리키는 포인터
void doubleByPointer(int* p) {
    // TODO
}

// n 을 2배로 만듭니다. (pass by reference)
//   n : 수정할 정수에 대한 참조
void doubleByRef(int& n) {
    // TODO
}

// r 의 count 와 rate 필드를 갱신합니다.
//   r        : 수정할 Record 에 대한 참조
//   newCount : r.count 에 저장할 새 수량
//   newRate  : r.rate 에 저장할 새 단가
void updateRecord(Record& r, int newCount, double newRate) {
    // TODO
}

// r 의 label, count, rate 를 한 줄로 출력합니다.
//   r : 읽기 전용 const 참조
//   출력 형식: "<label> <count> <rate>\n"  (rate 는 소수점 2자리)
void printRecord(const Record& r) {
    // TODO
}
