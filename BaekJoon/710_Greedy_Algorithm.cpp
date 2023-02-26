/*
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
*/

// 회의실 배정
// 1931

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int N;
std::vector<std::pair<int, int>> vec;

bool comp(const std::pair<int, int> &a, const std::pair<int, int> &b);

int main() {
    int start, end;

    std::cin >> N;

    for (int idx = 0; idx < N; idx++) {
        std::cin >> start >> end;
        vec.push_back({start, end});
    }

    std::sort(vec.begin(), vec.end(), comp);

    end = vec[0].second;
    int count = 1;

    for (int idx = 1; idx < N; idx++) {
        if (end <= vec[idx].first) {
            count++;
            end = vec[idx].second;
        }
    }

    std::cout << count << '\n';

    return 0;
}

bool comp(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}