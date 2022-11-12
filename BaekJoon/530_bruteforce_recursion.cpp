/*
// 암호 만들기
// 1759

#include <algorithm>
#include <iostream>
#include <vector>

void DFS(int count, int cur);
void print();
void push(int count, int index);
void pop();

int L, C, consonants = 0, vowels = 0;
std::vector<char> input, result;

int main() {
    char alphabet;

    std::cin >> L >> C;

    for (int index = 0; index < C; index++) {
        std::cin >> alphabet;
        input.push_back(alphabet);
    }

    std::sort(input.begin(), input.end());
    DFS(0, 0);

    return 0;
}

void DFS(int count, int cur) {
    if (count == L) {
        print();
        return;
    }

    for (int index = cur; index < C; index++) {
        push(count, index);
        DFS(count + 1, index + 1);
        pop();
    }
}

void print() {
    if (vowels >= 1 && consonants >= 2) {
        for (int index = 0; index < L; index++)
            std::cout << result.at(index);
        std::cout << "\n";
    }
}

void push(int count, int index) {

    if (count == 0 && C - index < L)
        return;

    if (input.at(index) == 'a' || input.at(index) == 'e' ||
        input.at(index) == 'i' || input.at(index) == 'o' ||
        input.at(index) == 'u')
        vowels++;
    else
        consonants++;

    result.push_back(input.at(index));
}

void pop() {
    if (!result.empty()) {
        if (result.at(result.size() - 1) == 'a' ||
            result.at(result.size() - 1) == 'e' ||
            result.at(result.size() - 1) == 'i' ||
            result.at(result.size() - 1) == 'o' ||
            result.at(result.size() - 1) == 'u')
            vowels--;
        else
            consonants--;
        result.pop_back();
    }
}
*/

// 퇴사
// 14501

/*
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int N, num1, num2, max = 0;
    std::vector<int> T, P;

    std::cin >> N;

    std::vector<int> result(N + 1, 0);

    for (int index = 0; index < N; index++) {
        std::cin >> num1 >> num2;
        T.push_back(num1);
        P.push_back(num2);
    }

    for (int index = N - 1; index >= 0; index--) {
        if (T.at(index) + index > N)
            result.at(index) = result.at(index + 1);

        else
            result.at(index) =
                std::max(result.at(index + T.at(index)) + P.at(index),
                         result.at(index + 1));
    }

    for (int index = 0; index < N; index++)
        max = std::max(max, result.at(index));

    std::cout << max << "\n";
    return 0;
}
*/

#include <algorithm>
#include <iostream>
#include <vector>

void DFS(std::vector<int> &T, std::vector<int> &p, int index);
int main() {
    int N, num1, num2, max = 0;
    std::vector<int> T, P;

    std::cin >> N;

    std::vector<int> result(N + 1, 0);

    for (int index = 0; index < N; index++) {
        std::cin >> num1 >> num2;
        T.push_back(num1);
        P.push_back(num2);
    }

    for (int index = N - 1; index >= 0; index--) {
        if (T.at(index) + index > N)
            result.at(index) = result.at(index + 1);

        else
            result.at(index) =
                std::max(result.at(index + T.at(index)) + P.at(index),
                         result.at(index + 1));
    }

    for (int index = 0; index < N; index++)
        max = std::max(max, result.at(index));

    std::cout << max << "\n";
    return 0;
}
