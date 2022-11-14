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

/*
// 스타트와 링크
// 14889

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int combination(int n, int r);
void DFS(int count, int cur);
void cal();

int N, min = 10000000, cases, check = 0;
bool done = false;
std::vector<std::vector<int>> S;
std::vector<int> input, vec, Num;

int main() {
    int num;

    std::cin >> N;
    cases = combination(N, N / 2);

    for (int index = 0; index < N; index++)
        Num.push_back(index);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> num;
            input.push_back(num);
        }
        S.push_back(input);

        input.clear();
        input.shrink_to_fit();
    }

    DFS(0, 0);

    return 0;
}

int combination(int n, int r) {
    if (n == r || r == 0)
        return 1;
    else
        return combination(n - 1, r - 1) + combination(n - 1, r);
}

void DFS(int count, int cur) {
    if (count == N / 2) {
        cal();
        return;
    }

    for (int index = cur; index < N; index++) {
        vec.push_back(Num.at(index));
        DFS(count + 1, index + 1);
        if (done)
            return;
        vec.pop_back();
    }
}

void cal() {
    int sum = 0;
    int another_sum = 0;

    std::vector<int> another_vec;
    std::vector<bool> visited(N, false);

    for (int index = 0; index < N/2; index++)
        visited.at(vec.at(index)) = true;

    for (int index = 0; index < N; index++)
        if(!visited.at(index))
            another_vec.push_back(index);
    for (int y = 0; y < vec.size(); y++)
        for (int x = 0; x < vec.size(); x++)
            if (x != y)
                sum += S[vec.at(y)].at(vec.at(x));

    for (int y = 0; y < vec.size(); y++)
        for (int x = 0; x < vec.size(); x++)
            if (x != y)
                another_sum += S[another_vec.at(y)].at(another_vec.at(x));

    min = std::min(min, std::abs(sum - another_sum));
    check++;

    another_vec.clear();
    another_vec.shrink_to_fit();

    if (check == cases) {
        std::cout << min << "\n";
        done = true;
    }
}
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

void DFS(int count, int cur);
void cal();

int N, min = 10000000;
std::vector<std::vector<int>> S;
std::vector<bool> visited(22, false);

int main() {
    int num;
    std::vector<int> input;

    std::cin >> N;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            std::cin >> num;
            input.push_back(num);
        }
        S.push_back(input);
        input.clear();
        input.shrink_to_fit();
    }

    DFS(0, 0);

    std::cout << min << "\n";
    return 0;
}

void DFS(int count, int cur) {
    if (count == N / 2) {
        cal();
        return;
    }

    for (int index = cur; index < N/2; index++) {
        visited.at(index) = true;
        DFS(count + 1, index + 1);
        visited.at(index) = false;
    }
}

void cal() {
    int start = 0;
    int link = 0;

    for (int y = 0; y < N/2; y++) {
        for (int x = 0; x < N/2; x++) {
            if (visited.at(y) && visited.at(x))
                start += S[y].at(x);
            if (!visited.at(y) && !visited.at(x))
                link += S[y].at(x);
        }
    }

    int result = std::abs(start - link);
    min = std::min(min, result);
}