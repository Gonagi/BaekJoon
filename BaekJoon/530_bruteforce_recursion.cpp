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