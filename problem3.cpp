/*
 * Problem 3: Function Overloading and Return by Reference
 *
 * 학번:
 * 이름:
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


// double 타입 인자 1개를 받는 describe 함수를 작성하세요.
//   출력 형식: "double: <x>\n"  (소수점 2자리)
//   n      : 배열의 원소 수
//   x      : 출력해야 할 인자


// arr[i] 에 대한 참조를 반환합니다.
//   arr    : 정수 배열의 첫 번째 원소를 가리키는 포인터
//   n      : 배열의 원소 수
//   i      : 반환할 원소의 인덱스
//   반환값 : arr[i] 에 대한 int&
int& elementAt(int* arr, int n, int i) {
    // TODO
    return arr[0];
}
