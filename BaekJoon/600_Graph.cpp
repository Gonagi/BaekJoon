/*
// ABCDE
// 13023

#include <iostream>
#include <vector>

int N, M;
bool is_exist = false;
std::vector<int> linked[2001];
bool visited[2001];

void DFS(int cur, int depth);

int main() {
    int a, b;
    std::cin >> N >> M;

    for (int i = 0; i < M; i++) {
        std::cin >> a >> b;
        linked[a].push_back(b);
        linked[b].push_back(a);
    }

    for (int index = 0; index < N; index++)
        DFS(index, 0);

    if (!is_exist)
        std::cout << 0 << "\n";

    return 0;
}

void DFS(int cur, int depth) {
    if (depth == 4) {
        std::cout << 1 << "\n";
        is_exist = true;
        return;
    }

    for (int index = 0; index < linked[cur].size(); index++) {
        int next = linked[cur].at(index);
        if (!visited[next] && !is_exist) {
            visited[cur] = true;
            DFS(next, depth + 1);
            visited[cur] = false;
        }
    }
}
*/

/*
// 시간초과

#include <iostream>

int N, M, is_exist = 0;
int Arr[2001][2001]{0};

void DFS(int cur, int depth);

int main() {
    int from, to;

    std::cin >> N >> M;

    for (int i = 0; i < M; i++) {
        std::cin >> from >> to;
        Arr[from][to] = 1;
        Arr[to][from] = 1;
    }

    int i = 0;
    while (i++ < N && !is_exist)
        DFS(i, 0);

    std::cout << is_exist << "\n";

    return 0;
}

void DFS(int cur, int depth) {
    if (depth == 4) {
        is_exist = 1;
        return;
    }

    for (int index = 0; index < N; index++) {
        if ((Arr[cur][index] != 0) && !is_exist) {
            Arr[cur][index] = 0;
            Arr[index][cur] = 0;
            DFS(index, depth + 1);
            Arr[cur][index] = 1;
            Arr[index][cur] = 1;
        }
    }
}
*/

/*
// DFS와 BFS
// 1260

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int N, M, V;
bool is_exist = false, visited[1000]{false};
int vec[1001][1001]{0};
std::queue<int> que;

void DFS(int cur);
void BFS(int cur, int count);

int main() {
    int from, to;
    std::cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        std::cin >> from >> to;
        vec[from][to] = 1;
        vec[to][from] = 1;
    }

    DFS(V);
    std::cout << "\n";

    for (int i = 1; i <= N; i++)
        visited[i] = false;

    BFS(V, 0);
    std::cout << "\n";

    return 0;
}

void DFS(int cur) {
    visited[cur] = true;
    std::cout << cur << " ";

    for (int next_index = 1; next_index <= N; next_index++) {
        if (vec[cur][next_index] == 1 && !visited[next_index])
            DFS(next_index);
    }
    return;
}

void BFS(int cur, int count) {
    que.push(cur);
    visited[cur] = true;
    std::cout << cur << " ";

    while (!que.empty()) {
        int next = que.front();
        que.pop();

        for (int next_index = 1; next_index <= N; next_index++) {
            if (vec[next][next_index] == 1 && !visited[next_index]) {
                que.push(next_index);
                visited[next_index] = true;
                std::cout << next_index << " ";
            }
        }
    }
}
*/

/*
#include <iostream>
#include <queue>
#include <vector>

int N, M, V;
int linked[1001][1001];
bool visited[1001];
std::queue<int> que;

void DFS(int cur, int count);
void BFS(int cur, int count);

int main() {
    int a, b;
    std::cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        std::cin >> a >> b;
        linked[a][b]++;
        linked[b][a]++;
    }

    DFS(V, 0);

    std::cout << "\n";
    for (int i = 1; i <= N; i++)
        visited[i] = false;

    BFS(V, 0);

    return 0;
}

void DFS(int cur, int count) {
    visited[cur] = true;
    std::cout << cur << " ";

    for (int index = 1; index <= N; index++)
        if (!visited[index] && linked[cur][index] > 0)
            DFS(index, count + 1);
}

void BFS(int cur, int count) {
    que.push(cur);
    std::cout << cur << " ";
    visited[cur] = true;

    while (!que.empty()) {
        int from = que.front();
        que.pop();

        for (int to = 1; to <= N; to++) {
            if (!visited[to] && linked[from][to] > 0 && linked[to][from] > 0) {
                linked[from][to]--;
                linked[to][from]--;

                std::cout << to << " ";
                que.push(to);
                visited[to] = true;
            }
        }
    }
}
*/

/*
// 연결 요소의 개수
// 11724

#include <iostream>
#include <vector>

int N, M, count = 0;
bool linked[1001][1001];
bool visited[1001];

void input();
void count_link();
void DFS(int num);

int main() {
    input();
    count_link();
    std::cout << count << "\n";

    return 0;
}

void input() {
    int u, v;
    std::cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        std::cin >> u >> v;
        linked[u][v] = true;
        linked[v][u] = true;
    }
}

void count_link() {
    for (int num = 1; num <= N; num++) {
        if (!visited[num]) {
            visited[num] = true;
            DFS(num);
            count++;
        }
    }
}

void DFS(int num) {
    for (int to = 1; to <= N; to++) {
        if (!visited[to] && linked[num][to]) {
            visited[to] = true;
            DFS(to);
        }
    }
}
*/

/*
// 이분 그래프
// 1707

#include <cstring>
#include <iostream>
#include <vector>

int K, V, E, u, v;
bool is_exist = true, visited[20002];
int check[20002];
std::vector<int> linked[20002];

void input();
void print();
void clear();
void DFS(int num, int count);

int main() {
    std::cin >> K;

    for (int i = 1; i <= K; i++) {
        input();
        for (int j = 1; j <= V; j++) {
            if (!visited[j]) {
                memset(visited, false, sizeof(visited));
                memset(check, 0, sizeof(check));
                DFS(j, 0);
                if (!is_exist)
                    break;
            }
        }
        print();
        clear();
    }
    return 0;
}

void input() {
    std::cin >> V >> E;
    for (int i = 1; i <= E; i++) {
        std::cin >> u >> v;
        linked[u].push_back(v);
        linked[v].push_back(u);
    }
}

void print() {
    if (is_exist)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}

void clear() {
    is_exist = true;

    for (int a = 1; a <= V; a++)
        linked[a].clear();
    memset(visited, false, sizeof(visited));
    memset(check, 0, sizeof(check));
}

void DFS(int num, int count) {
    if (count == V)
        return;

    visited[num] = true;

    for (int index = 0; index < linked[num].size(); index++) {
        int next = linked[num][index];
        if (is_exist) {
            if (!visited[next]) {
                if (check[num] % 2 == 0)
                    check[next] += 1;
                else
                    check[next] += 2;

                DFS(next, count + 1);
                continue;
            }

            if ((check[next] % 2 == 0 && check[num] % 2 == 0) ||
                (check[next] % 2 == 1 && check[num] % 2 == 1))
                is_exist = false;
        }
    }
}
*/

/*
// DFS
#include <cstring>
#include <iostream>
#include <vector>

#define RED 1
#define BLUE 2

int K, V, E, u, v;
bool is_exist = true;
std::vector<int> visited;
std::vector<std::vector<int>> linked;

void input();
void DFS(int num);
bool is_bipartite_graph();

int main() {
    std::cin >> K;

    while (K--) {
        input();

        for (int i = 1; i <= V; i++)
            if (visited[i] == 0)
                DFS(i);

        if (is_bipartite_graph())
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
    return 0;
}

void input() {
    std::cin >> V >> E;

    visited.assign(V + 1, false);
    linked.assign(V + 1, std::vector<int>(0, 0));

    for (int i = 1; i <= E; i++) {
        std::cin >> u >> v;
        linked[u].emplace_back(v);
        linked[v].emplace_back(u);
    }
}

void DFS(int num) {

    if (!visited.at(num))
        visited.at(num) = RED;

    for (int index = 0; index < linked[num].size(); index++) {
        int next_num = linked[num].at(index);
        if (!visited[next_num]) {
            if (visited.at(num) == RED)
                visited.at(next_num) = BLUE;
            else if (visited.at(num) == BLUE)
                visited.at(next_num) = RED;
            DFS(next_num);
        }
    }
}

bool is_bipartite_graph() {
    for (int index = 1; index <= V; index++) {
        for (int i = 0; i < linked[index].size(); i++) {
            int next_num = linked[index].at(i);
            if (visited.at(index) == visited.at(next_num))
                return false;
        }
    }

    return true;
}
*/

/*
// BFS

#include <iostream>
#include <queue>
#include <vector>
#define RED 1
#define BLUE 2

int K, V, E;
std::vector<int> visited;
std::vector<std::vector<int>> linked;

void input();
void BFS(int num);
bool is_bipartite_graph();

int main() {
    std::cin >> K;

    while (K--) {
        input();
        for (int num = 1; num <= V; num++)
            if (visited.at(num) == 0)
                BFS(num);

        if (is_bipartite_graph())
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
    return 0;
}

void input() {
    int u, v;

    std::cin >> V >> E;

    visited.assign(V + 1, false);
    linked.assign(V + 1, std::vector<int>(0, 0));

    for (int i = 1; i <= E; i++) {
        std::cin >> u >> v;
        linked[u].emplace_back(v);
        linked[v].emplace_back(u);
    }
}

void BFS(int num) {
    std::queue<int> que;
    que.push(num);
    visited.at(num) = RED;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (int index = 0; index < linked[cur].size(); index++) {
            int next_num = linked[cur].at(index);
            if (visited.at(next_num) == 0) {
                que.push(next_num);

                if (visited.at(cur) == RED)
                    visited.at(next_num) = BLUE;
                else if (visited.at(cur) == BLUE)
                    visited.at(next_num) = RED;
            }
        }
    }
}

bool is_bipartite_graph() {
    for (int num = 1; num <= V; num++) {
        for (int index = 0; index < linked[num].size(); index++) {
            int next_num = linked[num].at(index);
            if (visited.at(num) == visited.at(next_num))
                return false;
        }
    }
    return true;
}
*/

/*
// 단지번호붙이기
// 2667

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int N, count;
std::string str;
std::vector<int> result;
std::vector<std::vector<int>> map;

struct direction {
    int y, x;
};

direction dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void input_house();
void DFS(int y, int x);
void solve();

int main() {
    input_house();
    solve();

    std::sort(result.begin(), result.end());
    std::cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++)
        std::cout << result.at(i) << "\n";

    return 0;
}

void input_house() {
    std::vector<int> input;
    std::cin >> N;

    for (int y = 0; y < N; y++) {
        std::cin >> str;
        for (int x = 0; x < N; x++)
            input.push_back(str.at(x) - '0');
        map.push_back(input);

        input.clear();
        input.shrink_to_fit();
    }
}

void DFS(int y, int x) {
    map[y][x] = -1;
    count++;

    int next_y = y;
    int next_x = x;

    for (int d = 0; d < 4; d++) {
        next_y = y + dir[d].y;
        next_x = x + dir[d].x;
        if ((0 <= next_y && next_y <= N - 1 && 0 <= next_x &&
             next_x <= N - 1) && map[next_y][next_x] == 1)
            DFS(next_y, next_x);
    }
    return;
}

void solve() {
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            if (map[y][x] == 1) {
                DFS(y, x);
                result.push_back(count);
                count = 0;
            }
}
*/

/*
// 섬의 개수
// 4963

#include <iostream>
#include <queue>
#include <vector>

struct direction {
    int y, x;
};

direction dir[8] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                    {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

int w, h;
std::vector<std::vector<int>> map;
std::vector<int> input;

void input_map();
void BFS(int y, int x);
void clear_map();

int main() {
    while (1) {
        int count = 0;

        std::cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        input_map();

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (map[y][x] == 1) {
                    BFS(y, x);
                    count++;
                }
            }
        }
        std::cout << count << "\n";

        clear_map();
    }
    return 0;
}

void input_map() {
    int num;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            std::cin >> num;
            input.push_back(num);
        }
        map.push_back(input);

        input.clear();
        input.shrink_to_fit();
    }
}

void BFS(int y, int x) {
    direction cur = {y, x};
    map[y][x] = -1;
    std::queue<struct direction> que;
    que.push(cur);

    while (!que.empty()) {
        cur = que.front();
        direction next{cur.y, cur.x};
        que.pop();

        for (int d = 0; d < 8; d++) {
            next.y = cur.y + dir[d].y;
            next.x = cur.x + dir[d].x;
            if ((0 <= next.y && next.y <= h - 1 && 0 <= next.x &&
                 next.x <= w - 1) &&
                map[next.y][next.x] == 1) {
                que.push(next);
                map[next.y][next.x] = -1;
            }
        }
    }
}

void clear_map() {
    for (int y = 0; y < h; y++) {
        map[y].clear();
        map[y].shrink_to_fit();
    }
    map.clear();
    map.shrink_to_fit();
}
*/

/*
// 미로 탐색
// 2178

// BFS
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Direction {
    int y, x;
};

Direction dir[4]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int N, M;
std::vector<std::vector<int>> map;
std::vector<std::vector<int>> check;

std::queue<struct Direction> que;

void input_map();
void BFS(int y, int x);

int main() {
    input_map();

    BFS(0, 0);

    std::cout << check[N - 1][M - 1] << "\n";

    return 0;
}

void input_map() {
    std::string str;
    std::vector<int> input_x;
    std::vector<int> check_x;

    std::cin >> N >> M;
    check_x.assign(M, 0);
    check.assign(N, check_x);

    for (int y = 0; y < N; y++) {
        std::cin >> str;
        for (int x = 0; x < M; x++)
            input_x.push_back(str.at(x) - '0');

        map.push_back(input_x);

        input_x.clear();
        input_x.shrink_to_fit();
    }
}

void BFS(int y, int x) {
    Direction cur{y, x};
    que.push(cur);
    map[y][x] = -1;
    check[y][x] = 1;

    while (!que.empty()) {
        cur = que.front();
        que.pop();
        Direction next(cur);

        for (int d = 0; d < 4; d++) {
            next.y = cur.y + dir[d].y;
            next.x = cur.x + dir[d].x;

            if (0 <= next.y && next.y <= N - 1 && 0 <= next.x &&
                next.x <= M - 1 && map[next.y][next.x] == 1) {
                que.push(next);
                map[next.y][next.x] = -1;
                check[next.y][next.x] = check[cur.y][cur.x] + 1;
            }
        }
    }
}
*/

/*
// DFS 시간초과

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Direction {
    int y, x;
};

Direction dir[4]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int N, M, count = 1, min = 10001;
std::vector<std::vector<int>> map;

void input_map();
void DFS(int y, int x);

int main() {
    input_map();

    DFS(0, 0);

    std::cout << min << "\n";

    return 0;
}

void input_map() {
    std::string str;
    std::vector<int> input_x;

    std::cin >> N >> M;

    for (int y = 0; y < N; y++) {
        std::cin >> str;
        for (int x = 0; x < M; x++)
            input_x.push_back(str.at(x) - '0');

        map.push_back(input_x);

        input_x.clear();
        input_x.shrink_to_fit();
    }
}

void DFS(int y, int x) {
    if (y == N - 1 && x == M - 1) {
        min = std::min(min, count);
        return;
    }

    for (int d = 0; d < 4; d++) {
        int next_y = y + dir[d].y;
        int next_x = x + dir[d].x;

        if (0 <= next_y && next_y <= N - 1 && 0 <= next_x && next_x <= M - 1 &&
            map[next_y][next_x] == 1) {
            count++;
            map[y][x] = -1;
            DFS(next_y, next_x);
            map[y][x] = 1;
            count--;
        }
    }
}
*/

// 나이트의 이동
// 7562

#include <iostream>
#include <queue>
#include <vector>
#define current 1
#define visited -1
#define destination 2

struct Direction {
    int y, x;
};

Direction dir[8] = {{-2, 1}, {-1, 2}, {1, 2},   {2, 1},
                    {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

int I, from_y, from_x, to_y, to_x, count;
std::vector<std::vector<int>> map, check;

void input();
void BFS();
bool can_move(int y, int x);

int main() {
    int t;

    std::cin >> t;

    while (t--) {
        input();
        BFS();
        std::cout << check[to_y][to_x] << "\n";
    }
    return 0;
}

void input() {
    std::vector<int> input_x;

    std::cin >> I;

    input_x.assign(I, 0);
    map.assign(I, input_x);
    check.assign(I, input_x);

    std::cin >> from_y >> from_x;
    std::cin >> to_y >> to_x;

    map[from_y][from_x] = current;
    map[to_y][to_x] = destination;
}

void BFS() {
    Direction cur{from_y, from_x}, next;
    std::queue<Direction> que;
    que.push(cur);
    map[from_y][from_x] = visited;

    while (!que.empty()) {
        cur.y = que.front().y;
        cur.x = que.front().x;
        que.pop();

        for (int d = 0; d < 8; d++) {
            next.y = cur.y + dir[d].y;
            next.x = cur.x + dir[d].x;
            if (can_move(next.y, next.x) && map[next.y][next.x] != visited) {
                que.push(next);
                map[next.y][next.x] = visited;
                check[next.y][next.x] = check[cur.y][cur.x] + 1;
            }
        }
    }
}

bool can_move(int y, int x) {
    if (y < 0 || x < 0 || y > I - 1 || x > I - 1)
        return false;
    return true;
}
