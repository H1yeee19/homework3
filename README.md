## 개요

C++의 기본 타입, 구조체, 포인터, 흐름 제어를 실습합니다.  
총 4문제로 구성되어 있으며, 각 `problem*.cpp` 파일에 있는 함수를 구현하세요.  
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
homework2/
├── main.cpp              ← 수정 금지. 테스트 실행 로직 (테스트 데이터 파일을 읽어 실행).
├── problem1.cpp          ← Problem 1 구현 (Type Arithmetic and auto)
├── problem2.cpp          ← Problem 2 구현 (struct and Flow Control)
├── problem3.cpp          ← Problem 3 구현 (Pointer)
├── problem4.cpp          ← Problem 4 구현 (Integrated)
├── test2.sh              ← 채점 스크립트 (macOS / Linux)
├── test2.bat             ← 채점 스크립트 (Windows)
├── .github/
│   └── workflows/
│       └── grade.yml     ← GitHub Actions 자동 채점 워크플로우
└── Test/
    ├── case1.txt         ← 테스트 케이스 1 입력 데이터
    ├── case2.txt         ← 테스트 케이스 2 입력 데이터
    ├── case3.txt         ← 테스트 케이스 3 입력 데이터
    ├── expected1.txt     ← 테스트 케이스 1 기대 출력
    ├── expected2.txt     ← 테스트 케이스 2 기대 출력
    └── expected3.txt     ← 테스트 케이스 3 기대 출력
```

---

## 문제 1 — Type Arithmetic and `auto` (`problem1.cpp`)

| 함수 | 설명 |
|---|---|
| `int add(int a, int b)` | `a + b` 반환 |
| `int divide(int a, int b)` | `a / b` 정수 나눗셈 반환 |
| `double toDouble(int a, int b)` | `static_cast<double>(a) / b` 반환 |

`main.cpp` 에서는 `auto` 타입 추론, `char` 산술 연산, `unsigned char` 오버플로우도 함께 출력합니다.

---

## 문제 2 — struct and Flow Control (`problem2.cpp`)

`Product { name, quantity, price }` 배열을 처리합니다.

| 함수 | 설명 |
|---|---|
| `findMostExpensive(products, n)` | 가격이 가장 높은 상품의 인덱스 반환 |
| `countAboveThreshold(products, n, threshold)` | `quantity > threshold` 인 상품 수 반환 |
| `totalValue(products, n)` | 전체 재고 가치(`quantity × price` 합) 반환 |
| `priceCategory(price)` | `< 2.0` → `"cheap"`, `< 5.0` → `"medium"`, 나머지 → `"expensive"` |

---

## 문제 3 — Pointer (`problem3.cpp`)

| 함수 | 설명 |
|---|---|
| `void increment(int* p)` | `p` 가 가리키는 값을 1 증가 |
| `int* findMax(int* arr, int n)` | 최대값 원소의 포인터 반환 (빈 배열이면 `nullptr`) |
| `void mySwap(int* a, int* b)` | 두 값 교환 |

---

## 문제 4 — Integrated (`problem4.cpp`)

`Student { name, scores[3], average }` 배열을 처리합니다.

| 함수 | 설명 |
|---|---|
| `void computeAverage(Student* s)` | `scores[0..2]` 의 평균을 `s->average` 에 저장 |
| `Student* findTopStudent(students, n)` | 평균이 가장 높은 학생의 포인터 반환 |
| `void applyBonus(students, n, threshold, bonus)` | `average < threshold` 인 학생의 각 점수에 `bonus` 추가 (최대 100) |

---

## 테스트 방법

```bash
# macOS / Linux
bash test2.sh

# Windows
test2.bat
```

테스트 케이스 3개를 순서대로 실행하며 각각 `PASS` / `FAIL` 을 출력합니다.  
`FAIL` 인 경우 기대 출력과 실제 출력의 diff 를 함께 보여줍니다.

테스트 데이터는 `Test/case1.txt` ~ `Test/case3.txt` 에 있으며,  
`main.cpp` 는 이 파일을 읽어 실행합니다 (`./hw2_main Test/case1.txt` 형식).

---

## 제출 방법 (git)

```bash
git add problem1.cpp problem2.cpp problem3.cpp problem4.cpp
git commit -m "학번 이름"
git push
```

- push 후 저장소의 **Actions 탭** 에서 자동 채점 결과를 확인할 수 있습니다.
- 마감 전까지 몇 번이든 다시 제출할 수 있습니다.
