// 동전 0
// 11047

#include <algorithm>
#include <iostream>
#include <vector>

int N, K, result;
std::vector<int> vec;

int main() {
    int A;
    std::cin >> N >> K;

    for (int idx = 0; idx < N; idx++) {
        std::cin >> A;
        vec.push_back(A);
    }

    std::sort(vec.rbegin(), vec.rend());

    for (auto i : vec) {
        if (i > K)
            continue;

        result += K / i;
        K -= (K / i) * i;

        if (K == 0)
            break;
    }

    std::cout << result << '\n';

    return 0;
}