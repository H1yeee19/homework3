/*
 * Problem 4: Integrated — struct + reference + const reference + conditional
 *
 * 학번: 202501772
 * 이름: 유혜주
 *
 * ─────────────────────────────────────────────────────────────
 * 아래 네 함수를 완성하세요.
 *
 *  updateScore(student, newScore)    : student 의 score 를 newScore 로 갱신합니다.
 *  isPassed(student, passingScore)   : student.score >= passingScore 이면 true 를 반환합니다.
 *  printStudent(student)             : student 의 id 와 score 를 출력합니다.
 *  findTopScorer(students, n)        : score 가 가장 높은 학생의 참조를 반환합니다.
 * ─────────────────────────────────────────────────────────────
 */
#include <iostream>
using namespace std;

struct Student {
    int id;
    int score;
};

// student 의 score 를 newScore 로 갱신합니다.
//   student  : 수정할 Student 에 대한 참조
//   newScore : 새 점수
void updateScore(Student& student, int newScore) {
    student.score = newScore;
}

// student.score >= passingScore 이면 true, 미만이면 false 를 반환합니다.
//   student      : 읽기 전용 const 참조
//   passingScore : 합격 기준 점수
bool isPassed(const Student& student, int passingScore) {
    return student.score >= passingScore;
}

// student 의 id 와 score 를 출력합니다.
//   student : 읽기 전용 const 참조
//   출력 형식: "ID: <id>  Score: <score>\n"
void printStudent(const Student& student) {
    cout << "ID: " << student.id << " Score: " << student.score << endl;
}

// score 가 가장 높은 학생의 참조를 반환합니다.
//   students : Student 배열의 첫 번째 원소를 가리키는 포인터
//   n        : 배열의 원소 수 (n >= 1)
//   반환값   : 최고 점수 학생에 대한 Student&
Student& findTopScorer(Student* students, int n) {
    Student* top = &students[0];
    for (int i=1; i<n; i++) {
        if (students[i].score > top->score) {
            top = &students[i];
        }
    }
    return *top;
}
