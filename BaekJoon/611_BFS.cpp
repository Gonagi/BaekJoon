/*
// 뱀과 사다리 게임
// 16928

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
*/

// 데스 나이트
// 16948

#include <iostream>
#include <queue>
#include <utility>

struct Direction {
    int y, x;
};
Direction dir[6]{{-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1}};
int N, r1, c1, r2, c2;
bool visited[200][200];

void BFS();
bool movable(int y, int x);

int main() {
    std::cin >> N;
    std::cin >> r1 >> c1 >> r2 >> c2;
    BFS();
    return 0;
}

void BFS() {
    std::queue<std::pair<Direction, int>> que;
    que.push({{r1, c1}, 0});

    while (!que.empty()) {
        Direction cur{que.front().first};
        int count = que.front().second;
        visited[cur.y][cur.x] = true;
        que.pop();

        if (cur.y == r2 && cur.x == c2) {
            std::cout << count << "\n";
            exit(0);
        }
        for (int idx = 0; idx < 6; idx++) {
            Direction next{cur.y + dir[idx].y, cur.x + dir[idx].x};
            if (movable(next.y, next.x) && !visited[next.y][next.x]) {
                que.push({next, count + 1});
                visited[next.y][next.x] = true;
            }
        }
    }
    std::cout << -1 << "\n";
}

bool movable(int y, int x) {
    if (y < 0 || y >= N || x < 0 || x >= N)
        return false;
    return true;
}