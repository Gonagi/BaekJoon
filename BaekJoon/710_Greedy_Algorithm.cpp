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

/*
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
*/

// 행렬
// 1080

#include <iostream>
#include <string>
#include <vector>

int N, M;
std::vector<std::vector<int>> board1, board2;

void input();
int solve();
void change(int y, int x);

int main() {
    input();
    std::cout << solve() << '\n';

    return 0;
}

void input() {
    std::string str;
    std::cin >> N >> M;

    board1.assign(N, std::vector<int>(M));
    board2.assign(N, std::vector<int>(M));

    for (int y = 0; y < N; y++) {
        std::cin >> str;
        for (int x = 0; x < M; x++) {
            board1[y][x] = str[x] - '0';
        }
    }

    for (int y = 0; y < N; y++) {
        std::cin >> str;
        for (int x = 0; x < M; x++) {
            board2[y][x] = str[x] - '0';
        }
    }
}

int solve() {
    int count = 0;
    for (int y = 0; y < N - 2; y++) {
        for (int x = 0; x < M - 2; x++) {
            if (board1[y][x] != board2[y][x]) {
                change(y, x);
                count++;
            }
        }
    }

    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            if (board1[y][x] != board2[y][x])
                return -1;

    return count;
}

void change(int y, int x) {
    for (int cur_y = y; cur_y < y + 3; cur_y++) {
        for (int cur_x = x; cur_x < x + 3; cur_x++) {
            if (board1[cur_y][cur_x] == 0)
                board1[cur_y][cur_x] = 1;
            else
                board1[cur_y][cur_x] = 0;
        }
    }
}