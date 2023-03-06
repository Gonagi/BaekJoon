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

/*
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
*/

/*
// 전구와 스위치
// 2138

#include <iostream>
#include <string>

int N, count1, count2;
std::string start1, start2, end;

void change(std::string &str, int cur);

int main() {

    std::cin >> N;
    std::cin >> start1 >> end;

    start2 = start1;

    for (int cur = 0; cur < start1.size() - 1; cur++) {
        if (start1[cur] != end[cur]) {
            change(start1, cur + 1);
            count1++;
        }
    }

    if (start1 != end) {
        change(start2, 0);
        count2++;

        for (int cur = 0; cur < start1.size() - 1; cur++) {
            if (start2[cur] != end[cur]) {
                change(start2, cur + 1);
                count2++;
            }
        }

        if (start2 != end)
            std::cout << -1 << '\n';
        else
            std::cout << count2 << '\n';
    }
    else
        std::cout << count1 << '\n';

    return 0;
}

void change(std::string &str, int cur) {
    if (cur == 0) {
        if (str[0] == '0')
            str[0] = '1';
        else
            str[0] = '0';

        if (str[1] == '0')
            str[1] = '1';
        else
            str[1] = '0';
    }

    else if (cur == str.size() - 1) {
        if (str[cur - 1] == '0')
            str[cur - 1] = '1';
        else
            str[cur - 1] = '0';

        if (str[cur] == '0')
            str[cur] = '1';
        else
            str[cur] = '0';
    }

    else {
        for (int index = cur - 1; index <= cur + 1; index++) {
            if (str[index] == '0')
                str[index] = '1';
            else
                str[index] = '0';
        }
    }
}
*/

/*
// 동전 뒤집기
// 1258

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int N, min = 987654321;
std::vector<std::vector<char>> board;

void input();
int reverse(int count);

int main() {
    input();

    for (int count = 0; count < (1 << N); count++)
        min = std::min(min, reverse(count));

    std::cout << min << '\n';

    return 0;
}

void input() {
    std::string str;
    std::vector<char> board_x;

    std::cin >> N;

    for (int y = 0; y < N; y++) {
        std::cin >> str;
        for (int x = 0; x < N; x++) {
            board_x.push_back(str[x]);
        }

        board.push_back(board_x);
        board_x.clear();
        board_x.shrink_to_fit();
    }
}

int reverse(int count) {
    int ret = 0;

    for (int y = 0; y < N; y++) {
        int H_count = 0;
        int T_count = 0;

        for (int x = 0; x < N; x++) {
            if (((count >> x) & 1) == 1) {
                if (board[y][x] == 'H')
                    T_count++;
                else
                    H_count++;
            } else {
                if (board[y][x] == 'H')
                    H_count++;
                else
                    T_count++;
            }
        }

        ret += std::min(H_count, T_count);
    }

    return ret;
}
*/

// 보석 도둑
// 1202

#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int N, K;
std::vector<std::pair<int, int>> jewel;
std::vector<int> bag;

void input();

int main() {
    input();

    int j = 0;
    long long sum = 0;
    std::priority_queue<int> que;

    for (int b = 0; b < K; b++) {
        while (j < N && bag[b] >= jewel[j].first) {
            que.push(jewel[j].second);
            j++;
        }
        if (!que.empty()) {
            sum += que.top();
            que.pop();
        }
    }

    std::cout << sum << '\n';
    return 0;
}

void input() {
    int M, V, C;
    std::cin >> N >> K;

    for (int idx = 0; idx < N; idx++) {
        std::cin >> M >> V;
        jewel.push_back({M, V});
    }

    for (int idx = 0; idx < K; idx++) {
        std::cin >> C;
        bag.push_back(C);
    }

    std::sort(jewel.begin(), jewel.end());
    std::sort(bag.begin(), bag.end());
}