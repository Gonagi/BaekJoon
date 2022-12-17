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

// 숨바꼭질 4
// 13913

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int N, K, num[100001];
std::vector<bool> visited;
std::vector<int> result;

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
    visited.at(N) = true;

    while (!que.empty()) {
        int cur = que.front().first;
        int count = que.front().second;
        que.pop();

        if (cur == K) {
            int index = cur;
            while (index != N) {
                result.push_back(num[index]);
                index = num[index];
            }

            std::cout << count << "\n";

            for (int i = count - 1; i >= 0; i--)
                std::cout << result.at(i) << " ";
            std::cout << K << "\n";
            return;
        }

        if (0 < cur && !visited[cur - 1]) {
            que.push(std::make_pair(cur - 1, count + 1));
            visited[cur - 1] = true;
            num[cur - 1] = cur;
        }
        if (cur < 100000 && !visited[cur + 1]) {
            que.push(std::make_pair(cur + 1, count + 1));
            visited[cur + 1] = true;
            num[cur + 1] = cur;
        }
        if (cur <= 50000 && !visited[2 * cur]) {
            que.push(std::make_pair(2 * cur, count + 1));
            visited[2 * cur] = true;
            num[2 * cur] = cur;
        }
    }
}