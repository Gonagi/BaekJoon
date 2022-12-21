/*
// 숨바꼭질
// 1697

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int N, K, result;
std::vector<int> visited;

void BFS();

int main() {
    std::cin >> N >> K;

    visited.assign(100001, false);

    BFS();

    return 0;
}

void BFS() {
    std::queue<std::pair<int, int>> que;
    que.push(std::make_pair(N, 0));
    visited[N] = true;

    while (!que.empty()) {
        int num = que.front().first;
        int count = que.front().second;
        que.pop();

        if (num == K) {
            std::cout << count << "\n";
            break;
        }

        if (1 <= num && !visited[num - 1]) {
            visited[num - 1] = true;
            que.push(std::make_pair(num - 1, count + 1));
        }

        if (num < 100000 && !visited[num + 1]) {
            visited[num + 1] = true;
            que.push(std::make_pair((num + 1), count + 1));
        }
        if (num <= 50000 && !visited[2 * num]) {
            visited[2 * num] = true;
            que.push(std::make_pair((2 * num), count + 1));
        }
    }
}
*/

/*
// 숨바꼭질 4
// 13913

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int N, K, arr[100001];
std::vector<bool> visited(100001, false);
std::vector<int> result;

void BFS();

int main() {
    std::cin >> N >> K;

    BFS();

    return 0;
}

void BFS() {
    std::queue<std::pair<int, int>> que;
    que.push(std::make_pair(N, 0));
    visited[N] = true;

    while (!que.empty()) {
        int cur = que.front().first;
        int count = que.front().second;
        que.pop();

        if (cur == K) {
            while (cur != N) {
                result.push_back(cur);
                cur = arr[cur];
            }
            result.push_back(cur);

            std::cout << count << "\n";

            for (int i = count; i >= 0; i--)
                std::cout << result.at(i) << " ";

            return;
        }

        if (0 < cur && !visited[cur - 1]) {
            que.push(std::make_pair(cur - 1, count + 1));
            visited[cur - 1] = true;
            arr[cur - 1] = cur;
        }

        if (cur < 100000 && !visited[cur + 1]) {
            que.push(std::make_pair(cur + 1, count + 1));
            visited[cur + 1] = true;
            arr[cur + 1] = cur;
        }

        if (cur <= 50000 && !visited[2 * cur]) {
            que.push(std::make_pair(2 * cur, count + 1));
            visited[2 * cur] = true;
            arr[2 * cur] = cur;
        }
    }
}
*/

/*
// 이모티콘
// 14226

#include <iostream>
#include <queue>

struct element {
    int num, clipboard, count;
};

int S;
bool visited[1001][1001];
void BFS();

int main() {
    std::cin >> S;

    BFS();

    return 0;
}

void BFS() {
    element cur{1, 0, 0};
    std::queue<element> que;
    que.push(cur);

    while (!que.empty()) {
        int cur_num = que.front().num;
        int cur_clipboard = que.front().clipboard;
        int cur_count = que.front().count;
        que.pop();

        if (cur_num == S) {
            std::cout << cur_count << "\n";
            break;
        }

        if (0 < cur_num && cur_num < 1001) {
            if (!visited[cur_num][cur_num]) {
                que.push(element{cur_num, cur_num, cur_count + 1});
                visited[cur_num][cur_num] = true;
            }

            if (0 < cur_clipboard && cur_num + cur_clipboard < 1001 && !visited[cur_num + cur_clipboard][cur_clipboard]) {
                que.push(element{cur_num + cur_clipboard, cur_clipboard, cur_count + 1});
                visited[cur_num + cur_clipboard][cur_clipboard] = true;
            }

            if (2 <= cur_num && !visited[cur_num - 1][cur_clipboard]) {
                que.push(element{cur_num - 1, cur_clipboard, cur_count + 1});
                visited[cur_num - 1][cur_clipboard] = true;
            }
        }
    }
}
*/

/*
// 숨바꼭질 3
// 13549

#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

int N, K;
std::vector<bool> visited(100001, false);

void BFS();

int main() {
    std::cin >> N >> K;

    BFS();

    return 0;
}

void BFS() {
    std::queue<std::pair<int, int>> que;
    que.push(std::make_pair(N, 0));
    visited[N] = true;

    while (!que.empty()) {
        int cur = que.front().first;
        int cal = cur;
        int count = que.front().second;
        que.pop();

        if (cur == K) {
            std::cout << count << "\n";
            return;
        }

        if (0 <= cur && cur <= 100000) {
            while (cal <= 50000 && std::abs(K - cal) > std::abs(K - 2 * cal)) {
                cal *= 2;

                if (cal == K) {
                    std::cout << count << "\n";
                    return;
                }
                visited[cal] = true;
                que.push(std::make_pair(cal, count));
            }

            if (cur < 100000 && !visited[cur + 1]) {
                que.push(std::make_pair(cur + 1, count + 1));
                visited[cur + 1] = true;
            }

            if (0 < cur && !visited[cur - 1]) {
                que.push(std::make_pair(cur - 1, count + 1));
                visited[cur - 1] = true;
            }
        }
    }
}
*/

#include <iostream>
#include <queue>
#include <vector>

int N, K;
bool visited[100001];

void min_second();

int main() {
    std::cin >> N >> K;

    min_second();

    return 0;
}

void min_second() {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> que;

    que.push(std::make_pair(0, N));
    visited[N] = true;

    while (!que.empty()) {
        int cur_sec = que.top().first;
        int cur = que.top().second;
        que.pop();

        if (cur == K) {
            std::cout << cur_sec << "\n";
            return;
        }

        if (2 * cur <= 100000 && !visited[2 * cur]) {
            que.push(std::make_pair(cur_sec, 2 * cur));
            visited[2 * cur] = true;
        }

        if (cur < 100000 && !visited[cur + 1]) {
            que.push(std::make_pair(cur_sec + 1, cur + 1));
            visited[cur + 1] = true;
        }

        if (0 < cur && !visited[cur - 1]) {
            que.push(std::make_pair(cur_sec + 1, cur - 1));
            visited[cur - 1] = true;
        }
    }
}