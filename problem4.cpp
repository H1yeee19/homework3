/*
 * Problem 4: Integrated — struct + pointer + loop + conditional
 *
 * 학번:
 * 이름:
 *
 * ─────────────────────────────────────────────────────────────
 * 아래 세 함수를 완성하세요.
 *
 *  computeAverage(s)           : s->scores[0..2] 의 평균을 s->average 에 저장합니다.
 *                                힌트: 3.0 으로 나눠야 실수 나눗셈이 됩니다.
 *  findTopStudent(students, n) : 평균이 가장 높은 학생의 포인터를 반환합니다.
 *                                n == 0 이면 nullptr 를 반환합니다.
 *  applyBonus(students, n, t, b) : average < t 인 학생의 scores[0..2] 에
 *                                   각각 b 를 더합니다.
 *                                   단, 각 점수는 100 을 초과할 수 없습니다.
 * ─────────────────────────────────────────────────────────────
 */
#include <string>
using namespace std;

struct Student {
    string name;
    int    scores[3];
    double average;
};

// TODO: s->scores[0..2] 의 평균을 s->average 에 저장하세요.
//   s : 평균을 계산할 Student 를 가리키는 포인터 (null 이 아님을 보장)
//       힌트: 3.0 으로 나눠야 실수 나눗셈이 됩니다.
void computeAverage(Student* s) {
    // TODO
}

// TODO: average 가 가장 높은 학생의 포인터를 반환하세요.
//   students : Student 구조체 배열의 첫 번째 원소를 가리키는 포인터
//   n        : 배열의 원소 수  (n == 0 이면 nullptr 반환)
Student* findTopStudent(Student* students, int n) {
    // TODO
    return nullptr;
}

// TODO: average < threshold 인 학생의 scores[i] 에 bonus 를 더하세요.
//   students  : Student 구조체 배열의 첫 번째 원소를 가리키는 포인터
//   n         : 배열의 원소 수
//   threshold : 보너스 적용 기준 평균 — average 가 이 값 미만인 학생에게 적용
//   bonus     : 각 점수에 더할 값  (각 점수는 100 을 초과할 수 없습니다)
void applyBonus(Student* students, int n, double threshold, int bonus) {
    // TODO
}
