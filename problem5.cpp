/*
 * Problem 5: refactoring
 *
 * 학번:
 * 이름:
 *
 * ─────────────────────────────────────────────────────────────
 * 프로그램의 동작을 바꾸지 않고 코드를 리팩터링하세요.
 *
 * 다음 내용을 중심으로 개선해 주세요.
 * - Meaningful names
 * - Small functions
 * - Do one thing
 * - One level of abstraction
 * - Reduce duplicated code
 * - Reduce deeply nested conditionals
 * - Appropriate use of reference / const reference
 * - Consistent formatting
 *
 * 요구 사항
 * 1. 프로그램의 출력 결과와 동작을 유지해 주세요.
 * 2. p, calc, f, run, r, n과 같이 의미가 불분명한 이름을 개선해 주세요.
 * 3. 하나의 함수에서 여러 역할을 수행하고 있다면 적절히 분리해 주세요.
 * 4. 중복되는 quality 범위 처리 코드를 줄여 주세요.
 * 5. 중첩된 if 문을 읽기 쉬운 형태로 개선해 주세요.
 * 6. 값을 변경하지 않는 함수 parameter에는 가능한 경우 const를 적용해 주세요.
 * 7. 불필요한 복사가 발생하지 않도록 reference를 적절히 사용해 주세요.
 * 8. 아직 배우지 않은 class, inheritance, template, design pattern은 사용하지 마세요.
 *
 * 반드시 유지할 동작
 * 리팩터링 전후에 다음 동작이 동일해야 합니다.
 * - 세 날짜 동안의 item 상태 변화
 * - Total price 계산
 * - High-quality item 개수 계산
 * - Expired item 개수 계산
 * - Cheese 검색
 * - 검색된 Cheese 가격 500 감소
 *
 * ─────────────────────────────────────────────────────────────
 */
/*
 * 과제
 * 1. 가장 먼저 개선하고 싶었던 부분은 무엇이었나요?
 * >
 * 2. 함수 하나를 새로 추출했다면, 그 함수가 담당하는 한 가지 역할은 무엇인가요?
 * >
 * 3. Item&와 const Item& 중 어떤 것을 사용했으며 그 이유는 무엇인가요?
 * >
 * 4. 리팩터링 전보다 코드의 의도가 더 잘 드러나는 부분 한 곳을 설명해 주세요.
 * >
 */
#include <iostream>
#include <string>

struct Item {
    std::string name;
    int days;
    int quality;
    int price;
};

void p(Item& a, int d, bool verbose) {
    // update inventory state and print information
    if (a.name == "Cheese") {
        if (a.days > 0) {
            if (a.quality < 50) {
                a.quality = a.quality + 1;
            }
        } else {
            if (a.quality < 49) {
                a.quality = a.quality + 2;
            } else {
                a.quality = 50;
            }
        }
    } else if (a.name == "Ticket") {
        if (a.days > 10) {
            if (a.quality < 50)
                a.quality = a.quality + 1;
        } else if (a.days > 5) {
            if (a.quality < 49)
                a.quality = a.quality + 2;
            else
                a.quality = 50;
        } else if (a.days > 0) {
            if (a.quality < 47)
                a.quality = a.quality + 3;
            else
                a.quality = 50;
        } else {
            a.quality = 0;
        }
    } else if (a.name == "Legendary") {
        // nothing changes
    } else {
        if (a.days > 0) {
            if (a.quality > 0)
                a.quality = a.quality - 1;
        } else {
            if (a.quality > 1)
                a.quality = a.quality - 2;
            else
                a.quality = 0;
        }
    }

    if (a.name != "Legendary") {
        a.days = a.days - d;
    }

    if (a.quality < 0)
        a.quality = 0;

    if (a.quality > 50 && a.name != "Legendary")
        a.quality = 50;

    if (verbose) {
        std::cout << a.name << ": "
                  << "days=" << a.days
                  << ", quality=" << a.quality
                  << ", price=" << a.price
                  << std::endl;
    }
}

int calc(Item items[], int n, int mode) {
    int r = 0;

    for (int i = 0; i < n; ++i) {
        if (mode == 0) {
            r = r + items[i].price;
        } else if (mode == 1) {
            if (items[i].quality >= 40)
                r = r + 1;
        } else if (mode == 2) {
            if (items[i].days <= 0)
                r = r + 1;
        }
    }

    return r;
}

Item* f(Item items[], int n, const std::string& s) {
    Item* r = nullptr;

    for (int i = 0; i < n; ++i) {
        if (items[i].name == s) {
            r = &items[i];
            break;
        }
    }

    return r;
}

void run(Item items[], int n, int days, bool verbose) {
    for (int day = 1; day <= days; ++day) {
        if (verbose) {
            std::cout << "======== Day " << day << " ========" << std::endl;
        }

        for (int i = 0; i < n; ++i) {
            p(items[i], 1, verbose);
        }

        int total = calc(items, n, 0);
        int good = calc(items, n, 1);
        int expired = calc(items, n, 2);

        if (verbose) {
            std::cout << "Total price: " << total << std::endl;
            std::cout << "High-quality items: " << good << std::endl;
            std::cout << "Expired items: " << expired << std::endl;
        }
    }
}

int main() {
    Item items[] = {
        {"Normal", 5, 10, 1000},
        {"Cheese", 3, 20, 3000},
        {"Ticket", 8, 25, 5000},
        {"Legendary", 0, 80, 10000},
        {"Normal", 1, 2, 1500}
    };

    const int n = sizeof(items) / sizeof(items[0]);

    std::cout << "Before update" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << items[i].name << ": "
                  << items[i].days << ", "
                  << items[i].quality << std::endl;
    }

    run(items, n, 3, true);

    Item* x = f(items, n, "Cheese");

    if (x != nullptr) {
        x->price = x->price - 500;
        std::cout << "Discounted Cheese price: "
                  << x->price << std::endl;
    }

    return 0;
}