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