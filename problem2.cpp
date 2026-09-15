/*
 * Problem 2: struct and Flow Control
 *
 * 학번:
 * 이름:
 *
 * ─────────────────────────────────────────────────────────────
 * 아래 네 함수를 완성하세요.
 *
 *  findMostExpensive(products, n)          : 가격이 가장 높은 상품의 인덱스를 반환합니다.
 *  countAboveThreshold(products, n, thr)   : quantity > thr 인 상품의 수를 반환합니다.
 *  totalValue(products, n)                 : 모든 상품의 총 가치(quantity * price 합)를 반환합니다.
 *  priceCategory(price)                    : 가격대 문자열을 반환합니다.
 *                                            price < 2.0  →  "cheap"
 *                                            price < 5.0  →  "medium"
 *                                            otherwise    →  "expensive"
 * ─────────────────────────────────────────────────────────────
 */
#include <string>
using namespace std;

struct Product {
    string name;      // 상품 이름
    int    quantity;  // 재고 수량
    double price;     // 상품 가격 (단위: 달러)
};

// TODO: 가격이 가장 높은 상품의 인덱스를 반환하세요.
//   products : Product 구조체 배열 (원소 수: n)
//   n        : 배열의 원소 수
int findMostExpensive(Product products[], int n) {
    // TODO
    return 0;
}

// TODO: quantity 가 threshold 초과인 상품의 수를 반환하세요.
//   products  : Product 구조체 배열 (원소 수: n)
//   n         : 배열의 원소 수
//   threshold : 기준 수량 — 이 값을 초과(>)하는 상품을 셉니다.
int countAboveThreshold(Product products[], int n, int threshold) {
    // TODO
    return 0;
}

// TODO: 모든 상품의 총 가치(quantity * price 의 합)를 반환하세요.
//   products : Product 구조체 배열 (원소 수: n)
//   n        : 배열의 원소 수
double totalValue(Product products[], int n) {
    // TODO
    return 0.0;
}

// TODO: 가격대에 따른 카테고리 문자열을 반환하세요.
//   price : 상품의 가격 (double)
//           price < 2.0  →  "cheap"
//           price < 5.0  →  "medium"
//           otherwise    →  "expensive"
string priceCategory(double price) {
    // TODO
    return "";
}
