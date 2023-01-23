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

/*
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
*/

/*
// DSLR
// 9019

#include <iostream>
#include <queue>
#include <string>
#include <utility>

int T, A, B;
char DSLR[4] = {'D', 'S', 'L', 'R'};

void BFS();
int cal(int num, char ch);

int main() {

    std::cin >> T;

    for (int i = 0; i < T; i++) {
        std::cin >> A >> B;
        BFS();
    }

    return 0;
}

void BFS() {
    std::queue<std::pair<int, std::string>> que;
    que.push({A, ""});
    bool visited[10001]{false};

    while (!que.empty()) {
        int cur_num = que.front().first;
        std::string cur_str = que.front().second;
        visited[cur_num] = true;
        que.pop();

        if (cur_num == B) {
            std::cout << cur_str << "\n";
            break;
        }

        for (int idx = 0; idx < 4; idx++) {
            int next_num = cal(cur_num, DSLR[idx]);

            if (!visited[next_num]) {
                que.push({next_num, cur_str + DSLR[idx]});
                visited[next_num] = true;
            }
        }
    }
}

int cal(int num, char ch) {
    int d1 = num / 1000;
    int d2 = (num / 100) % 10;
    int d3 = (num / 10) % 10;
    int d4 = num % 10;

    switch (ch) {
    case 'D':
        num *= 2;
        if (num > 9999)
            num %= 10000;
        break;

    case 'S':
        num -= 1;
        if (num < 0)
            num = 9999;
        break;

    case 'L':
        num = ((d2 * 10 + d3) * 10 + d4) * 10 + d1;
        break;

    case 'R':
        num = ((d4 * 10 + d1) * 10 + d2) * 10 + d3;
        break;
    }
    return num;
}
*/

/*
// 연구소
// 14502

#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

struct Direction {
    int y, x;
};
Direction dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int N, M, max;
std::vector<Direction> vec;
std::vector<std::vector<int>> map;

void input();
void DFS(int count);
void BFS();
bool movable(int y, int x);
void cal(const std::vector<std::vector<int>> &map_2);

int main() {
    input();
    DFS(0);

    std::cout << max << "\n";
    return 0;
}

void input() {
    int num;
    std::vector<int> map_x;

    std::cin >> N >> M;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            std::cin >> num;
            if (num == 2)
                vec.push_back({y, x});
            map_x.push_back(num);
        }
        map.push_back(map_x);
        map_x.clear();
        map_x.shrink_to_fit();
    }
}

void DFS(int count) {
    if (count == 3) {
        BFS();
        return;
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (map[y][x] == 0) {
                map[y][x] = 1;
                DFS(count + 1);
                map[y][x] = 0;
            }
        }
    }
}

void BFS() {
    std::queue<Direction> que;
    std::vector<std::vector<int>> map_2;
    map_2.assign(map.size(), std::vector<int>(map.size()));
    std::copy(map.begin(), map.end(), map_2.begin());

    for (int idx = 0; idx < vec.size(); idx++)
        que.push(vec[idx]);

    while (!que.empty()) {
        Direction cur{que.front()};
        que.pop();

        for (int d = 0; d < 4; d++) {
            Direction next{cur};
            next.y += dir[d].y;
            next.x += dir[d].x;
            if (movable(next.y, next.x) && map_2[next.y][next.x] == 0) {
                map_2[next.y][next.x] = -1;
                que.push({next});
            }
        }
    }

    cal(map_2);
}

bool movable(int y, int x) {
    if (y < 0 || y >= N || x < 0 || x >= M)
        return false;
    return true;
}

void cal(const std::vector<std::vector<int>> &map_2) {
    int count = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (map_2[y][x] == 0)
                count++;
        }
    }

    if (max < count)
        max = count;
}
*/

// 돌 그룹
// 12886

#include <iostream>
#include <queue>
#include <utility>

int A, B, C, sum;
bool visited[1501][1501];

void BFS();

int main() {
    std::cin >> A >> B >> C;
    sum = A + B + C;
    if ((sum) % 3 != 0)
        std::cout << 0 << '\n';
    else {
        BFS();
        std::cout << 0 << '\n';
    }
    return 0;
}

void BFS() {
    std::queue<std::pair<int, int>> que;
    que.push({A, B});
    visited[A][B] = true;

    while (!que.empty()) {
        int num1 = que.front().first;
        int num2 = que.front().second;
        int num3 = sum - num1 - num2;
        que.pop();

        if (num1 == num2 && num1 == num3) {
            std::cout << 1 << '\n';
            exit(0);
        }

        if (num1 > num2) {
            if (!visited[num2 + num2][num1 - num2]) {
                visited[num2 + num2][num1 - num2] = true;
                que.push({num2 + num2, num1 - num2});
            }
        }
        if (num1 < num2) {
            if (!visited[num1 + num1][num2 - num1]) {
                visited[num1 + num1][num2 - num1] = true;
                que.push({num1 + num1, num2 - num1});
            }
        }
        if (num1 < num3) {
            if (!visited[num1 + num1][num3 - num1]) {
                visited[num1 + num1][num3 - num1] = true;
                que.push({num1 + num1, num3 - num1});
            }
        }
        if (num1 > num3) {
            if (!visited[num3 + num3][num1 - num3]) {
                visited[num3 + num3][num1 - num3] = true;
                que.push({num3 + num3, num1 - num3});
            }
        }
        if (num2 < num3) {
            if (!visited[num2 + num2][num3 - num2]) {
                visited[num2 + num2][num3 - num2] = true;
                que.push({num2 + num2, num3 - num2});
            }
        }
        if (num2 > num3) {
            if (!visited[num3 + num3][num2 - num3]) {
                visited[num3 + num3][num2 - num3] = true;
                que.push({num3 + num3, num2 - num3});
            }
        }
    }
}