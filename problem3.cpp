/*
 * Problem 3: Function Overloading and Return by Reference
 *
 * 학번: 202501772
 * 이름: 유혜주
 *
 * ─────────────────────────────────────────────────────────────
 * 아래 설명을 참고하여 함수를 직접 작성하세요.
 * ─────────────────────────────────────────────────────────────
 */
#include <iostream>
#include <iomanip>
using namespace std;

// int 타입 인자 1개를 받는 describe 함수를 작성하세요.
//   출력 형식: "int: <x>\n"
//   x      : 출력해야 할 인자

void describe(int x) {
    cout << "int: " << x << endl;
}


// double 타입 인자 1개를 받는 describe 함수를 작성하세요.
//   출력 형식: "double: <x>\n"  (소수점 2자리)
//   n      : 배열의 원소 수
//   x      : 출력해야 할 인자

void describe(double x) {
    cout << "double: " << fixed << setprecision(2) << x << endl;
}


// arr[i] 에 대한 참조를 반환합니다.
//   arr    : 정수 배열의 첫 번째 원소를 가리키는 포인터
//   n      : 배열의 원소 수
//   i      : 반환할 원소의 인덱스
//   반환값 : arr[i] 에 대한 int&
int& elementAt(int* arr, int n, int i) {
    if (i < 0 || i >= n) {
        throw std::out_of_range("Index out of bounds");
    }
    return arr[i];
}
