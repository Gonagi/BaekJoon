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

/*
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
*/

/*
// 벽 부수고 이동하기
// 2206

#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

struct Direction {
    int y, x;
};
Direction dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int N, M;
int visited[1000][1000][2];
std::vector<std::vector<int>> map;

void input();
void BFS();
bool movable(int y, int x);

int main() {
    input();
    BFS();
    std::cout << -1 << "\n";
    return 0;
}

void input() {
    std::string str;
    std::vector<int> map_x;

    std::cin >> N >> M;

    for (int y = 0; y < N; y++) {
        std::cin >> str;
        for (int x = 0; x < M; x++)
            map_x.push_back(str[x] - '0');
        map.push_back(map_x);

        map_x.clear();
        map_x.shrink_to_fit();
    }
}

void BFS() {
    std::queue<std::pair<Direction, int>> que;
    que.push({{0, 0}, 0});
    visited[0][0][0] = 0;

    while (!que.empty()) {
        Direction cur{que.front().first};
        int is_break = que.front().second;
        int count = visited[cur.y][cur.x][is_break];
        que.pop();

        if (cur.y == N - 1 && cur.x == M - 1) {
            std::cout << count + 1 << "\n";
            exit(0);
        }

        for (int d = 0; d < 4; d++) {
            Direction next{cur.y + dir[d].y, cur.x + dir[d].x};
            if (movable(next.y, next.x) && visited[next.y][next.x][is_break] == 0) {
                if (is_break == 1) { // 벽 부순적 있음
                    if (map[next.y][next.x] == 0) {
                        que.push({{next.y, next.x}, 1});
                        visited[next.y][next.x][1] = count + 1;
                    }
                } else { // 벽 부순적 없음
                    if (map[next.y][next.x] == 0) {
                        que.push({{next.y, next.x}, 0});
                        visited[next.y][next.x][0] = count + 1;
                    } else {
                        que.push({{next.y, next.x}, 1});
                        visited[next.y][next.x][1] = count + 1;
                    }
                }
            }
        }
    }
}

bool movable(int y, int x) {
    if (y < 0 || y >= N || x < 0 || x >= M)
        return false;
    return true;
}
*/

/*
// 벽 부수고 이동하기 4
// 16946

#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Direction {
    int y, x;
};
Direction dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int N, M;
std::vector<std::vector<int>> map, result;
std::vector<Direction> vec;

void input();
void BFS();
void cal(const std::vector<std::vector<int>> &copy_map, const std::vector<std::vector<int>> &check);
bool movable(int y, int x);

int main() {
    input();
    BFS();

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            std::cout << result[y][x];
        }
        std::cout << "\n";
    }
    return 0;
}

void input() {
    std::vector<int> map_x;
    std::string str;

    std::cin >> N >> M;

    for (int y = 0; y < N; y++) {
        std::cin >> str;
        for (int x = 0; x < M; x++) {
            map_x.push_back(str[x] - '0');
            if (str[x] == '1')
                vec.push_back({y, x});
        }
        map.push_back(map_x);

        map_x.clear();
        map_x.shrink_to_fit();
    }

    result = map;
}

void BFS() {
    auto copy_map(map), check(map);
    bool visited[1000][1000] = {false};
    int ch = 2;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (copy_map[y][x] == 0) {
                std::queue<Direction> que, store;
                int count = 0;
                que.push({y, x});
                store.push({y, x});

                while (!que.empty()) {
                    Direction cur = que.front();
                    visited[cur.y][cur.x] = true;

                    count++;
                    que.pop();

                    for (int d = 0; d < 4; d++) {
                        Direction next{cur.y + dir[d].y, cur.x + dir[d].x};
                        if (movable(next.y, next.x) && !visited[next.y][next.x] && copy_map[next.y][next.x] == 0) {
                            visited[next.y][next.x] = true;
                            que.push(next);
                            store.push(next);
                        }
                    }
                }

                while (!store.empty()) {
                    copy_map[store.front().y][store.front().x] = count;
                    check[store.front().y][store.front().x] = ch;
                    store.pop();
                }
                ch++;
            }
        }
    }

    for (int idx = 0; idx < vec.size(); idx++)
        copy_map[vec[idx].y][vec[idx].x] = 0;

    cal(copy_map, check);
}

void cal(const std::vector<std::vector<int>> &copy_map, const std::vector<std::vector<int>> &check) {
    for (int idx = 0; idx < vec.size(); idx++) {
        Direction cur(vec[idx]);
        std::vector<int> checking;
        int count = 1;

        for (int d = 0; d < 4; d++) {
            bool visited = false;
            Direction next({cur.y + dir[d].y, cur.x + dir[d].x});
            if (movable(next.y, next.x) && copy_map[next.y][next.x] != 0) {
                for (int i = 0; i < checking.size(); i++) {
                    if (checking[i] == check[next.y][next.x]) {
                        visited = true;
                        break;
                    }
                }
                if (!visited) {
                    checking.push_back(check[next.y][next.x]);
                    count += copy_map[next.y][next.x];
                }
            }
        }
        result[cur.y][cur.x] = count % 10;
        checking.clear();
        checking.shrink_to_fit();
    }
}

bool movable(int y, int x) {
    if (y < 0 || y >= N || x < 0 || x >= M)
        return false;
    return true;
}
*/

/*
// 벽 부수고 이동하기 2
// 14442

#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Direction {
    int y, x;
    int count = 1;
    int wall = 0;
};
Direction dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
std::vector<std::vector<int>> map;
int N, M, K;
int visited[1001][1001][11];

void input();
void BFS();
bool movable(int y, int x);

int main() {
    input();
    BFS();
    std::cout << -1 << "\n";
    return 0;
}

void input() {
    std::vector<int> map_x;
    std::string str;

    std::cin >> N >> M >> K;

    for (int y = 0; y < N; y++) {
        std::cin >> str;
        for (int x = 0; x < M; x++) {
            map_x.push_back(str[x] - '0');
        }
        map.push_back(map_x);

        map_x.clear();
        map_x.shrink_to_fit();
    }
}

void BFS() {
    std::queue<Direction> que;
    que.push({0, 0, 0, 0});
    visited[0][0][0] = 1;

    while (!que.empty()) {
        Direction cur = que.front();
        que.pop();

        if (cur.y == N - 1 && cur.x == M - 1) {
            std::cout << cur.count+1 << "\n";
            exit(0);
        }

        for (int d = 0; d < 4; d++) {
            Direction next{cur.y + dir[d].y, cur.x + dir[d].x};
            if (movable(next.y, next.x) && visited[next.y][next.x][cur.wall] == 0) {
                if (map[next.y][next.x] == 0 && visited[next.y][next.x][cur.wall] == 0) {
                    visited[next.y][next.x][cur.wall] = 1;
                    que.push({next.y, next.x, cur.count + 1, cur.wall});
                }
                if (map[next.y][next.x] == 1 && cur.wall < K && visited[next.y][next.x][cur.wall + 1] == 0) {
                    visited[next.y][next.x][cur.wall + 1] = 1;
                    que.push({next.y, next.x, cur.count + 1, cur.wall + 1});
                }
            }
        }
    }
}

bool movable(int y, int x) {
    if (y < 0 || y >= N || x < 0 || x >= M)
        return false;
    return true;
}
*/

/*
// 벽 부수고 이동하기 3
// 16933

#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Direction {
    int y, x;
    int count = 1;
    int wall = 0;
    bool is_night = false;
};
Direction dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
std::vector<std::vector<int>> map;
int N, M, K;
bool visited[1001][1001][11];

void input();
void BFS();
bool movable(int y, int x);

int main() {
    input();
    BFS();
    std::cout << -1 << "\n";
    return 0;
}

void input() {
    std::vector<int> map_x;
    std::string str;

    std::cin >> N >> M >> K;

    for (int y = 0; y < N; y++) {
        std::cin >> str;
        for (int x = 0; x < M; x++) {
            map_x.push_back(str[x] - '0');
        }
        map.push_back(map_x);

        map_x.clear();
        map_x.shrink_to_fit();
    }
}

void BFS() {
    std::queue<Direction> que;
    que.push({0, 0, 1, 0, false});

    while (!que.empty()) {
        Direction cur = que.front();
        que.pop();

        if (cur.y == N - 1 && cur.x == M - 1) {
            std::cout << cur.count << "\n";
            exit(0);
        }

        for (int d = 0; d < 4; d++) {
            Direction next{cur.y + dir[d].y, cur.x + dir[d].x};
            if (movable(next.y, next.x)) {
                if (map[next.y][next.x] == 0 && visited[next.y][next.x][cur.wall] == 0) {
                    visited[next.y][next.x][cur.wall] = 1;
                    que.push({next.y, next.x, cur.count + 1, cur.wall, !cur.is_night});
                } else if (map[next.y][next.x] == 1 && visited[next.y][next.x][cur.wall + 1] == 0 && cur.wall < K) {
                    if (!cur.is_night) { // 낮
                        visited[next.y][next.x][cur.wall + 1] = 1;
                        que.push({next.y, next.x, cur.count + 1, cur.wall + 1, !cur.is_night});
                    } else { // 밤
                        que.push({cur.y, cur.x, cur.count + 1, cur.wall, !cur.is_night});
                    }
                }
            }
        }
    }
}

bool movable(int y, int x) {
    if (y < 0 || x < 0 || y >= N || x >= M)
        return false;
    return true;
}
*/

/*
// 움직이는 미로 탈출
// 16954

#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Direcion {
    int y, x;
    int count = 1;
};
Direcion dir[9] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
std::vector<std::vector<char>> map;
int visited[8][8][9];

void input();
void BFS();
bool movable(int y, int x);

int main() {
    input();
    BFS();
    std::cout << 0 << '\n';
    return 0;
}

void input() {
    std::vector<char> map_x;
    std::string str;

    for (int y = 0; y < 8; y++) {
        std::cin >> str;
        for (int x = 0; x < 8; x++) {
            map_x.push_back(str[x]);
        }
        map.push_back(map_x);

        map_x.clear();
        map_x.shrink_to_fit();
    }
}

void BFS() {
    std::queue<Direcion> que;
    que.push({7, 0});
    visited[7][0][0] = 1;

    while (!que.empty()) {
        Direcion cur = que.front();
        que.pop();

        if (cur.y == 0 || cur.count > 8) {
            std::cout << 1 << "\n";
            exit(0);
        }

        for (int d = 0; d < 9; d++) {
            Direcion next{cur.y + dir[d].y, cur.x + dir[d].x};
            if (movable(next.y, next.x)) {
                if (next.y - cur.count + 1 >= 0 && map[next.y - cur.count + 1][next.x] == '#')
                    continue;
                if (next.y - cur.count >= 0 && map[next.y - cur.count][next.x] == '#')
                    continue;
                if (visited[next.y][next.x][cur.count + 1] == 0) {
                    visited[next.y][next.x][cur.count + 1] = 1;
                    que.push({next.y, next.x, cur.count + 1});
                }
            }
        }
    }
}

bool movable(int y, int x) {
    if (y < 0 || x < 0 || y >= 8 || x >= 8)
        return false;
    return true;
}
*/

/*
// 탈출
// 3055

#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

struct Direction {
    int y, x;
};
Direction dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
Direction S, D;
std::vector<std::vector<char>> map;
std::queue<Direction> W_que;
int R, C;
bool visited[50][50], water_visited[50][50];

void input();
void BFS();
void water_move();
bool movable(int y, int x);

int main() {
    input();
    BFS();
    std::cout << "KAKTUS" << '\n';
    return 0;
}

void input() {
    std::vector<char> map_x;
    std::string str;

    std::cin >> R >> C;

    for (int y = 0; y < R; y++) {
        std::cin >> str;
        for (int x = 0; x < C; x++) {
            if (str[x] == 'S') {
                S.y = y;
                S.x = x;
            } else if (str[x] == 'D') {
                D.y = y;
                D.x = x;
            } else if (str[x] == '*')
                W_que.push({y, x});
            map_x.push_back(str[x]);
        }
        map.push_back(map_x);

        map_x.clear();
        map_x.shrink_to_fit();
    }
}

void BFS() {
    std::queue<std::pair<Direction, int>> S_que;
    S_que.push({S, 0});
    visited[S.y][S.x] = 1;

    while (!S_que.empty()) {
        water_move();
        int S_count = S_que.size();

        for (int idx = 0; idx < S_count; idx++) {
            Direction cur = S_que.front().first;
            int cur_time = S_que.front().second;
            S_que.pop();

            if (cur.y == D.y && cur.x == D.x) {
                std::cout << cur_time << '\n';
                exit(0);
            }
            for (int d = 0; d < 4; d++) {
                Direction next{cur.y + dir[d].y, cur.x + dir[d].x};

                if (!movable(next.y, next.x))
                    continue;
                if (visited[next.y][next.x])
                    continue;
                if (map[next.y][next.x] == 'X' || map[next.y][next.x] == '*')
                    continue;
                visited[next.y][next.x] = true;
                S_que.push({next, cur_time + 1});
            }
        }
    }
}

void water_move() {
    int water_count = W_que.size();

    for (int idx = 0; idx < water_count; idx++) {
        Direction cur = W_que.front();
        water_visited[cur.y][cur.x] = true;
        W_que.pop();

        for (int d = 0; d < 4; d++) {
            Direction next{cur.y + dir[d].y, cur.x + dir[d].x};

            if (!movable(next.y, next.x))
                continue;
            if (water_visited[next.y][next.x])
                continue;
            if (map[next.y][next.x] == 'D' || map[next.y][next.x] == 'X' || map[next.y][next.x] == '*' || map[next.y][next.x] == 'S')
                continue;
            W_que.push(next);
            map[next.y][next.x] = '*';
            water_visited[next.y][next.x] = true;
        }
    }
}

bool movable(int y, int x) {
    if (y < 0 || x < 0 || y >= R || x >= C)
        return false;
    return true;
}
*/

// 아기 상어
// 16236

/*
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct Direction {
    int y, x;
};
Direction dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
Direction shark;
int N, map[21][21], check[21][21];
int min_distance = 401, min_y = 21, min_x = 21;
int eat_count, shark_size = 2;
int result;

void input();
void BFS(int y, int x);
bool movable(int y, int x);

int main() {
    input();
    while (1) {
        BFS(shark.y, shark.x);

        if (min_y != 21 && min_x != 21) {
            result += check[min_y][min_x];
            eat_count++;

            if (eat_count == shark_size) {
                shark_size++;
                eat_count = 0;
            }

            map[min_y][min_x] = 0;
            shark.y = min_y;
            shark.x = min_x;
        }

        else
            break;
    }

    std::cout << result << "\n";

    return 0;
}

void input() {
    std::cin >> N;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            std::cin >> map[y][x];
            if (map[y][x] == 9) {
                shark.y = y;
                shark.x = x;
                map[y][x] = 0;
            }
        }
    }
}

void BFS(int y, int x) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            check[i][j] = -1;
        }
    }

    std::queue<Direction> que;
    min_distance = 401;
    min_y = 21;
    min_x = 21;
    check[y][x] = 0;
    que.push({y, x});

    while (!que.empty()) {
        Direction cur = que.front();
        que.pop();

        for (int d = 0; d < 4; d++) {
            Direction next{cur.y + dir[d].y, cur.x + dir[d].x};

            if (!movable(next.y, next.x))
                continue;
            if (check[next.y][next.x] != -1 || map[next.y][next.x] > shark_size)
                continue;

            check[next.y][next.x] = check[cur.y][cur.x] + 1;

            if (map[next.y][next.x] != 0 && map[next.y][next.x] < shark_size) {
                if (min_distance > check[next.y][next.x]) {
                    min_y = next.y;
                    min_x = next.x;
                    min_distance = check[next.y][next.x];
                }

                else if (min_distance == check[next.y][next.x]) {
                    if (min_y == next.y) {
                        if (min_x > next.x) {
                            min_x = next.x;
                            min_y = next.y;
                        }
                    } else if (min_y > next.y) {
                        min_x = next.x;
                        min_y = next.y;
                    }
                }
            }

            que.push({next.y, next.x});
        }
    }
}

bool movable(int y, int x) {
    if (y < 0 || y >= N || x < 0 || x >= N)
        return false;
    return true;
}
*/

/*
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct Direction {
    int y, x;
    int count;
};

Direction dir[4] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
Direction shark;
std::vector<Direction> vec;
int N, fish_size = 2, eat;
int map[21][21];
int visited[21][21];

void input();
bool comp(const Direction &a, const Direction &b);
bool BFS(int y, int x);
bool movable(int y, int x);

int main() {
    input();
    while (BFS(shark.y, shark.x))
        ;
    std::cout << shark.count << '\n';
    return 0;
}

void input() {
    std::cin >> N;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            std::cin >> map[y][x];
            if (map[y][x] == 9) {
                shark.y = y;
                shark.x = x;
                map[y][x] = 0;
            }
        }
    }
}

bool comp(const Direction &a, const Direction &b) {
    if (a.count == b.count) {
        if (a.y== b.y)
            return a.x < b.x;
        return a.y < b.y;
    }
    return a.count < b.count;
}

bool BFS(int y, int x) {
    vec.clear();

    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            visited[y][x] = -1;

    std::queue<Direction> que;
    visited[y][x] = 0;
    que.push({y, x});

    while (!que.empty()) {
        Direction cur = que.front();
        que.pop();

        for (int d = 0; d < 4; d++) {
            Direction next{cur.y + dir[d].y, cur.x + dir[d].x};
            if (!movable(next.y, next.x))
                continue;
            if (visited[next.y][next.x] > -1 || map[next.y][next.x] > fish_size)
                continue;
            if (map[next.y][next.x] > 0 && map[next.y][next.x] < fish_size) {
                Direction edible{next.y, next.x, visited[cur.y][cur.x] + 1};
                vec.push_back(edible);
            }

            que.push(next);
            visited[next.y][next.x] = visited[cur.y][cur.x] + 1;
        }
    }

    if (!vec.empty()) {
        std::sort(vec.begin(), vec.end(), comp);
        auto Now = vec[0];

        shark.y = Now.y;
        shark.x = Now.x;
        shark.count += Now.count;

        map[shark.y][shark.x] = 0;
        eat++;
        if (eat == fish_size) {
            eat = 0;
            fish_size++;
        }
        return true;
    }
    return false;
}

bool movable(int y, int x) {
    if (y < 0 || x < 0 || y >= N || x >= N)
        return false;
    return true;
}
*/

/*
// 레이저 통신
// 6087

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Direction {
    int y, x;
    int mirror = 0;
    int D = -1;
};

int W, H, result = 987654321;
std::vector<std::vector<char>> map;
std::vector<Direction> C;
Direction dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void input();
void BFS();
bool movable(int y, int x);

int main() {
    input();
    BFS();
    std::cout << result << "\n";
    return 0;
}

void input() {
    std::string str;
    std::vector<char> map_x;

    std::cin >> W >> H;

    for (int y = 0; y < H; y++) {
        std::cin >> str;
        for (int x = 0; x < W; x++) {
            if (str[x] == 'C') {
                str[x] = '.';
                C.push_back({y, x});
            }
            map_x.push_back(str[x]);
        }
        map.push_back(map_x);
        map_x.clear();
        map_x.shrink_to_fit();
    }
}

void BFS() {
    std::queue<Direction> que;
    std::vector<std::vector<int>> visited(H, std::vector<int>(W, 0));
    que.push(C[0]);

    visited[C[0].y][C[0].x] = 987654321;

    while (!que.empty()) {
        Direction cur = que.front();
        que.pop();

        for (int d = 0; d < 4; d++) {
            Direction next{cur.y + dir[d].y, cur.x + dir[d].x};
            if (!movable(next.y, next.x) || map[next.y][next.x] == '*')
                continue;

            if (cur.D != d) {
                if (visited[next.y][next.x] == 0 || visited[next.y][next.x] >= cur.mirror + 1) {
                    visited[next.y][next.x] = cur.mirror + 1;
                    que.push({next.y, next.x, cur.mirror + 1, d});
                }
            } else {
                if (visited[next.y][next.x] == 0 || visited[next.y][next.x] > cur.mirror) {
                    visited[next.y][next.x] = cur.mirror;
                    que.push({next.y, next.x, cur.mirror, d});
                }
            }
        }
    }
    result = visited[C[1].y][C[1].x] - 1;
}

bool movable(int y, int x) {
    if (y < 0 || y >= H || x < 0 || x >= W)
        return false;
    return true;
}
*/

/*
// 소수 경로
// 1963

#include <cstring>
#include <iostream>
#include <queue>
#include <utility>

int A, B;
bool prime[10000];
bool visited[10000];

void BFS();
void check(std::queue<std::pair<int, int>> &que, int num);
void is_prime();

int main() {
    int T;
    is_prime();
    std::cin >> T;

    for (int idx = 0; idx < T; idx++)
        BFS();

    return 0;
}

void BFS() {
    std::cin >> A >> B;
    std::memset(visited, false, 10000);
    std::queue<std::pair<int, int>> que;
    visited[A] = true;
    que.push({A, 0});

    while (!que.empty()) {
        int cur = que.front().first;
        int count = que.front().second;

        if (cur == B) {
            std::cout << count << '\n';
            return;
        }
        check(que, cur);
    }
    std::cout << "Impossible" << '\n';
}

void check(std::queue<std::pair<int, int>> &que, int num) {
    int cur_num = que.front().first;
    int cur_count = que.front().second;

    for (int n = 1; n <= 9; n++) {
        num = n * 1000 + (num % 1000);
        if (!visited[num] && prime[num]) {
            que.push({num, cur_count + 1});
            visited[num] = true;
        }
    }

    num = cur_num;
    for (int n = 0; n <= 9; n++) {
        num = (num / 1000) * 1000 + (n * 100) + num % 100;
        if (!visited[num] && prime[num]) {
            que.push({num, cur_count + 1});
            visited[num] = true;
        }
    }

    num = cur_num;
    for (int n = 0; n <= 9; n++) {
        num = (num / 100) * 100 + (n * 10) + num % 10;
        if (!visited[num] && prime[num]) {
            que.push({num, cur_count + 1});
            visited[num] = true;
        }
    }

    num = cur_num;
    for (int n = 0; n <= 9; n++) {
        num = (num / 10) * 10 + n;
        if (!visited[num] && prime[num]) {
            que.push({num, cur_count + 1});
            visited[num] = true;
        }
    }
    que.pop();
}

void is_prime() {
    std::memset(prime, true, 10000);

    for (int num = 1000; num < 10000; num++) {
        for (int check = 2; check * check <= num; check++)
            if (num % check == 0) {
                prime[num] = false;
                break;
            }
    }
}
*/

/*
// 적록색약

#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Direction {
    int y, x;
};
Direction dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
std::vector<std::vector<char>> map;
int N, count;
bool visited[101][101];

void input();
void BFS(int y, int x);
void BFS2(int y, int x);
bool movable(int y, int x);

int main() {
    input();
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (!visited[y][x]) {
                BFS(y, x);
                count++;
            }
        }
    }

    std::cout << count << ' ';
    std::memset(visited, false, 10201);
    count = 0;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (!visited[y][x]) {
                BFS2(y, x);
                count++;
            }
        }
    }

    std::cout << count << '\n';
    return 0;
}

void input() {
    std::string str;
    std::vector<char> map_x;

    std::cin >> N;

    for (int y = 0; y < N; y++) {
        std::cin >> str;
        for (int x = 0; x < N; x++) {
            map_x.push_back(str[x]);
        }

        map.push_back(map_x);
        map_x.clear();
        map_x.shrink_to_fit();
    }
}

void BFS(int y, int x) {
    std::queue<Direction> que;
    que.push({y, x});
    visited[y][x] = true;
    char cur_char = map[y][x];

    while (!que.empty()) {
        Direction cur = que.front();
        visited[cur.y][cur.x] = true;
        que.pop();

        for (int d = 0; d < 4; d++) {
            Direction next{cur.y + dir[d].y, cur.x + dir[d].x};
            if (!movable(next.y, next.x))
                continue;
            if (visited[next.y][next.x])
                continue;
            if (cur_char != map[next.y][next.x])
                continue;
            que.push(next);
            visited[next.y][next.x] = true;
        }
    }
}

void BFS2(int y, int x) {
    std::queue<Direction> que;
    que.push({y, x});
    visited[y][x] = true;
    char cur_char = map[y][x];

    while (!que.empty()) {
        Direction cur = que.front();
        visited[cur.y][cur.x] = true;
        que.pop();

        for (int d = 0; d < 4; d++) {
            Direction next{cur.y + dir[d].y, cur.x + dir[d].x};
            if (!movable(next.y, next.x))
                continue;
            if (visited[next.y][next.x])
                continue;

            if ((cur_char == 'R' || cur_char == 'G') && (map[next.y][next.x] == 'R' || map[next.y][next.x] == 'G')) {
                que.push(next);
                visited[next.y][next.x] = true;
                continue;
            }

            if (cur_char != map[next.y][next.x])
                continue;
            que.push(next);
            visited[next.y][next.x] = true;
        }
    }
}

bool movable(int y, int x) {
    if (y < 0 || x < 0 || y >= N || x >= N)
        return false;
    return true;
}
*/

// 4연산
// 14395

#include <iostream>
#include <queue>
#include <string>
#include <utility>

long long s, t;

void BFS();

int main() {
    std::cin >> s >> t;
    if (s == t)
        std::cout << 0 << '\n';
    else
        BFS();

    return 0;
}

void BFS() {
    std::queue<std::pair<long long, std::string>> que;
    que.push({s, ""});
    bool sub = false, div = false;
    while (!que.empty()) {
        long long cur = que.front().first;
        std::string str = que.front().second;
        que.pop();

        if (cur == t) {
            std::cout << str << '\n';
            exit(0);
        }

        if (1 < cur * cur && cur * cur <= t)
            que.push({cur * cur, str + '*'});

        if (0 < cur + cur && cur + cur <= t)
            que.push({cur + cur, str + '+'});

        if (!sub) {
            que.push({0, str + '-'});
            sub = true;
        }

        if (cur != 0 && !div) {
            que.push({1, str + '/'});
            div = true;
        }
    }

    std::cout << -1 << '\n';
}