## 개요

C++의 reference, parameter passing, function overloading을 실습합니다.  
총 5문제로 구성되어 있으며, 각 `problem*.cpp` 파일에 있는 함수를 구현하세요.  
`main.cpp` 는 수정하지 않습니다.

---

## 개발 환경 준비

g++ 컴파일러가 필요합니다. 이미 설치되어 있다면 다음 단계로 넘어가세요.

| 운영체제 | 설치 방법 |
|---|---|
| Windows | [MSYS2](https://www.msys2.org/) 설치 후 `pacman -S mingw-w64-ucrt-x86_64-gcc` |
| macOS | 터미널에서 `xcode-select --install` |
| Linux (Ubuntu) | `sudo apt install build-essential` |

설치 확인:
```bash
g++ --version
```

---

## 파일 구조

```
homework3/
├── main.cpp              ← 수정 금지. 테스트 실행 로직 (테스트 데이터 파일을 읽어 실행).
├── problem1.cpp          ← Problem 1 구현 (Reference)
├── problem2.cpp          ← Problem 2 구현 (Parameter Passing)
├── problem3.cpp          ← Problem 3 구현 (Function Overloading)
├── problem4.cpp          ← Problem 4 구현 (Integrated)
├── problem5.cpp          ← Problem 5 구현 (Refactoring) — 자동 채점 대상 아님
├── test3.sh              ← 채점 스크립트 (macOS / Linux)
├── test3.bat             ← 채점 스크립트 (Windows)
└── Test/
    ├── case1.txt         ← 테스트 케이스 1 입력 데이터
    ├── case2.txt         ← 테스트 케이스 2 입력 데이터
    ├── case3.txt         ← 테스트 케이스 3 입력 데이터
    ├── expected1.txt     ← 테스트 케이스 1 기대 출력
    ├── expected2.txt     ← 테스트 케이스 2 기대 출력
    └── expected3.txt     ← 테스트 케이스 3 기대 출력
```

---

## 문제 1 — Reference (`problem1.cpp`)

C++ reference가 기존 object에 대한 alias라는 것을 확인합니다.  
reference를 통해 원본 값이 실제로 변경되는 것과, 포인터 방식과의 문법 차이를 비교합니다.

| 함수 | 설명 |
|---|---|
| `void addViaRef(int& r, int delta)` | `r` 이 참조하는 값에 `delta` 를 더함 — callee 수정이 caller 에 반영됨 |
| `int sumByConstRef(const int& a, const int& b)` | `a + b` 반환 — `const T&` 로 복사 없이 읽기 전용 접근 |
| `void swapByRef(int& a, int& b)` | 참조를 이용해 두 값 교환 — caller 에서 두 변수 모두 변경 확인 |
| `void incrementByRef(int& r)` | 참조를 이용해 값 1 증가 |
| `void incrementByPtr(int* p)` | 포인터를 이용해 값 1 증가 — `incrementByRef` 와 동작은 같고 문법 비교 |

`main.cpp` 의 `[Part 2]` 에서는 `const int& cr = val` 을 직접 선언해 원본과 주소가 같고 읽기 전용임도 함께 확인합니다.

---

## 문제 2 — Parameter Passing (`problem2.cpp`)

동일한 동작(값을 2배로 만들기)을 pass by value / pointer / reference 방식으로 구현하여  
각 방식에서 원본 argument가 변경되는지 확인합니다.  
`struct Record` 를 참조로 전달해 필드를 수정하는 것도 포함합니다.

| 함수 | 설명 |
|---|---|
| `int doubleByValue(int n)` | 로컬 복사본만 변경 — 호출자 변수 불변, 반환값으로 결과 확인 (pass by value) |
| `void doubleByPointer(int* p)` | `*p` 를 2배로 변경 — 호출자 변수 변경 (pass by pointer) |
| `void doubleByRef(int& n)` | `n` 을 2배로 변경 — 호출자 변수 변경 (pass by reference) |
| `void updateRecord(Record& r, int newCount, double newRate)` | `r` 의 `count`, `rate` 필드 갱신 |
| `void printRecord(const Record& r)` | `r` 의 내용 출력 — `const` 참조로 수정 불가 |

---

## 문제 3 — Function Overloading (`problem3.cpp`)

동일한 이름의 함수를 parameter 타입에 따라 overloading하고,  
배열 원소에 대한 참조를 반환해 호출자가 직접 수정할 수 있도록 합니다.

| 함수 | 설명 |
|---|---|
| `void describe(int x)` | `"int: <x>"` 출력 — int 버전 overloading |
| `void describe(double x)` | `"double: <x>"` 출력 (소수점 2자리) — double 버전 overloading |
| `int& elementAt(int* arr, int n, int i)` | `arr[i]` 에 대한 참조 반환 — 호출자가 이 참조로 원소를 수정 가능 |

---

## 문제 4 — Integrated (`problem4.cpp`)

`struct Student { int id; int score; }` 를 활용해  
reference, const reference, 조건문을 조합한 함수들을 구현합니다.

| 함수 | 설명 |
|---|---|
| `void updateScore(Student& student, int newScore)` | `student.score` 를 `newScore` 로 갱신 |
| `bool isPassed(const Student& student, int passingScore)` | `score >= passingScore` 이면 `true` 반환 |
| `void printStudent(const Student& student)` | `"ID: <id>  Score: <score>"` 형식으로 출력 |
| `Student& findTopScorer(Student* students, int n)` | `score` 가 가장 높은 학생의 참조 반환 |

---

## 문제 5 — Refactoring (`problem5.cpp`)

`problem5.cpp` 는 독립 실행 파일로, 자동 채점 대상이 아닙니다.  
프로그램의 동작을 유지하면서 아래 기준에 따라 코드를 개선하세요.

| 개선 항목 | 내용 |
|---|---|
| Meaningful names | `p`, `calc`, `f`, `run`, `r`, `n` 등 불명확한 이름 개선 |
| Small functions | 여러 역할을 하는 함수를 역할별로 분리 |
| const 적용 | 값을 변경하지 않는 파라미터에 `const` 또는 `const T&` 사용 |
| Reference 활용 | 불필요한 복사가 없도록 참조 적절히 사용 |
| 중복 코드 제거 | quality 범위 처리 등 반복되는 코드 통합 |
| 중첩 조건문 정리 | 깊게 중첩된 `if` 문을 읽기 쉬운 형태로 개선 |

파일 하단의 **과제 질문(1~4번)** 에 각 항목에 대한 답변을 작성하세요.

> `class`, `inheritance`, `template`, `design pattern` 은 아직 사용하지 마세요.  
> 리팩터링 전후에 프로그램 출력이 동일해야 합니다.

---

## 테스트 방법

```bash
# macOS / Linux
bash test3.sh

# Windows
test3.bat
```

테스트 케이스 3개를 순서대로 실행하며 각 문제별로 `PASS` / `FAIL` 을 출력합니다.  
`FAIL` 인 경우 기대 출력과 실제 출력의 차이를 함께 확인하세요.

테스트 데이터는 `Test/case1.txt` ~ `Test/case3.txt` 에 있으며,  
`main.cpp` 는 이 파일을 읽어 실행합니다 (`./hw3_main Test/case1.txt` 형식).

---

## 제출 방법 (git)

```bash
git add problem1.cpp problem2.cpp problem3.cpp problem4.cpp problem5.cpp
git commit -m "학번 이름"
git push
```

- push 후 저장소의 **Actions 탭** 에서 자동 채점 결과를 확인할 수 있습니다.
- 마감 전까지 몇 번이든 다시 제출할 수 있습니다.
