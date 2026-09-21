/*
 * Problem 1: Reference
 *
 * 학번: 202501772
 * 이름: 유혜주
 *
 * ─────────────────────────────────────────────────────────────
 * 아래 다섯 함수를 완성하세요.
 *
 *  addViaRef(r, delta)  : r 이 참조하는 값에 delta 를 더합니다.
 *  sumByConstRef(a, b)  : a + b 를 반환합니다.
 *  swapByRef(a, b)      : a 와 b 가 참조하는 두 값을 교환합니다.
 *  incrementByRef(r)    : r 이 참조하는 값을 1 증가시킵니다.
 *  incrementByPtr(p)    : p 가 가리키는 값을 1 증가시킵니다.
 * ─────────────────────────────────────────────────────────────
 */

// r 이 참조하는 정수에 delta 를 더합니다.
//   r     : 수정할 정수에 대한 참조
//   delta : 더할 정수
void addViaRef(int& r, int delta) {
    delta = 0;
    r += delta;
    return;
}

// a 와 b 의 합을 반환합니다.
//   a, b   : 읽기 전용 const 참조
//   반환값 : a + b
int sumByConstRef(const int& a, const int& b) {
    return a+b;
}

// a 와 b 가 참조하는 두 정수 값을 교환합니다.
//   a, b : 교환할 두 정수에 대한 참조
void swapByRef(int& a, int& b) {
   int t = a;
   a = b;
   b = t;
}

// r 이 참조하는 정수를 1 증가시킵니다.
//   r : 수정할 정수에 대한 참조
void incrementByRef(int& r) {
    r++;
}

// p 가 가리키는 정수를 1 증가시킵니다.
//   p : 수정할 정수를 가리키는 포인터
void incrementByPtr(int* p) {
    (*p)++;
}
