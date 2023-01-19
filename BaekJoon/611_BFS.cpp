#include <iostream>
#include <queue>
#include <utility>
#define Max 101

int N, M, ladder[Max], snake[Max];
bool visited[Max];

void input();
void BFS();

int main() {
    input();
    BFS();

    return 0;
}

void input() {
    int x, y, u, v;

    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        std::cin >> x >> y;
        ladder[x] = y;
    }

    for (int i = 0; i < M; i++) {
        std::cin >> u >> v;
        snake[u] = v;
    }
}

void BFS() {
    std::queue<std::pair<int, int>> que;
    que.push({1, 0});
    visited[1] = true;

    while (!que.empty()) {
        int cur = que.front().first;
        int count = que.front().second;
        visited[cur] = true;
        que.pop();

        if (cur == 100) {
            std::cout << count << "\n";
            exit(0);
        }

        for (int num = 1; num <= 6; num++) {
            if (!visited[cur + num]) {
                if (ladder[cur + num] == 0 && snake[cur + num] == 0) {
                    que.push({cur + num, count + 1});
                } else {
                    if (ladder[cur + num] != 0)
                        que.push({ladder[cur + num], count + 1});
                    else
                        que.push({snake[cur + num], count + 1});
                }
            }
        }
    }
}