/*
// BFS 스페셜 저지
// 16940

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int N, cur_index = 0;
std::vector<int> linked[100001], depth[100001], result, standard, compare;
std::vector<bool> visited(100001, false);

void input();
void BFS();
void solve();

int main() {
    input();
    BFS();
    solve();
    std::cout << 1 << "\n";
    return 0;
}

void input() {
    int dot1, dot2, num;
    std::cin >> N;

    for (int i = 0; i < N - 1; i++) {
        std::cin >> dot1 >> dot2;
        linked[dot1].push_back(dot2);
        linked[dot2].push_back(dot1);
    }

    for (int i = 0; i < N; i++) {
        std::cin >> num;
        result.push_back(num);
    }
}

void BFS() {
    std::queue<int> que;
    int cur_depth = 1;

    que.push(1);
    depth[1].push_back(cur_depth);
    visited[1] = true;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (int next_index = 0; next_index < linked[cur].size(); next_index++) {
            int next_num = linked[cur][next_index];
            if (!visited[next_num]) {
                que.push(next_num);
                visited[next_num] = true;
                depth[next_num].push_back(depth[cur][0] + 1);
            }
        }
    }
}

void solve() {
    int cur_depth = 1, count = 0, c = 0;

    if (result.at(0) != 1) {
        std::cout << 0 << "\n";
        exit(0);
    }

    while (1) {
        for (int index = 1; index <= N; index++) {
            if (depth[index][0] == cur_depth) {
                compare.push_back(index);
                count++;
                c++;
            }
        }

        for (int index = 0; index < count; index++)
            standard.push_back(result[cur_index + index]);

        std::sort(compare.begin(), compare.end());
        std::sort(standard.begin(), standard.end());

        if (compare != standard) {
            std::cout << 0 << "\n";
            exit(0);
        }

        if (c == N)
            return;
        compare.clear();
        standard.clear();
        compare.shrink_to_fit();
        standard.shrink_to_fit();

        cur_depth++;
        cur_index += count;
        count = 0;
    }
}
*/

/*
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int N, bfs_order[100001];
std::vector<int> linked[100001];
std::queue<int> result;

void input();
void BFS();
bool comp(const int &a, const int &b) {
    return bfs_order[a] < bfs_order[b];
}

int main() {
    input();
    BFS();
    return 0;
}

void input() {
    int dot1, dot2, num;
    std::cin >> N;

    for (int i = 0; i < N - 1; i++) {
        std::cin >> dot1 >> dot2;
        linked[dot1].push_back(dot2);
        linked[dot2].push_back(dot1);
    }

    for (int i = 1; i <= N; i++) {
        std::cin >> num;
        result.push(num);
        bfs_order[num] = i;
    }

    for (int i = 1; i <= N; i++)
        std::sort(linked[i].begin(), linked[i].end(), comp);
}

void BFS() {
    if (result.front() != 1) {
        std::cout << 0 << "\n";
        exit(0);
    }

    std::queue<int> que;
    que.push(1);
    result.pop();

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (auto i : linked[cur]) {
            if (i == result.front()) {
                que.push(result.front());
                result.pop();
            }
        }
    }

    if (result.empty())
        std::cout << 1 << "\n";
    else
        std::cout << 0 << "\n";
}
*/

/*
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int N, order[100001];
std::vector<int> linked[100001];
std::queue<int> result;

bool comp(const int &a, const int &b) {
    return order[a] < order[b];
}
void input();
void BFS();

int main() {
    input();
    BFS();
    return 0;
}

void input() {
    int dot1, dot2, num;
    std::cin >> N;

    for (int i = 0; i < N - 1; i++) {
        std::cin >> dot1 >> dot2;
        linked[dot1].push_back(dot2);
        linked[dot2].push_back(dot1);
    }

    for (int i = 0; i < N; i++) {
        std::cin >> num;
        result.push(num);
        order[num] = i;
    }

    for (int i = 1; i <= N; i++)
        std::stable_sort(linked[i].begin(), linked[i].end(), comp);
}

void BFS() {
    if (result.front() != 1) {
        std::cout << 0 << "\n";
        exit(0);
    }

    std::queue<int> que;
    que.push(1);
    result.pop();

    while (!que.empty()) {
        int cur_num = que.front();
        que.pop();

        for (auto next_num : linked[cur_num]) {
            if (next_num == result.front()) {
                que.push(next_num);
                result.pop();
            }
        }
    }

    if (result.empty())
        std::cout << 1 << "\n";
    else
        std::cout << 0 << "\n";
}
*/

/*
// DFS 스페셜 저지
// 16964

#include <algorithm>
#include <iostream>
#include <vector>

int N, count, order[100001];
bool check[100001];
std::vector<int> linked[100001], result;

void input();
void DFS(int cur_num);
bool comp(const int &a, const int &b) {
    return order[a] < order[b];
}

int main() {
    input();
    if (result[0] != 1) {
        std::cout << 0 << "\n";
        exit(0);
    }
    DFS(result[0]);
    std::cout << 1 << "\n";
    return 0;
}

void input() {
    int dot1, dot2, num;

    std::cin >> N;
    for (int i = 0; i < N - 1; i++) {
        std::cin >> dot1 >> dot2;
        linked[dot1].push_back(dot2);
        linked[dot2].push_back(dot1);
    }

    for (int i = 0; i < N; i++) {
        std::cin >> num;
        result.push_back(num);
        order[num] = i;
    }

    for (int i = 1; i <= N; i++)
        std::stable_sort(linked[i].begin(), linked[i].end(), comp);
}

void DFS(int cur_num) {
    if (check[cur_num]) {
        return;
    }

    check[cur_num] = true;

    for (int next_num : linked[cur_num])
        if (!check[next_num]) {
            count++;
            if (next_num != result[count]) {
                std::cout << 0 << "\n";
                exit(0);
            }
            DFS(next_num);
        }
}
*/

// 다리 만들기
// 2146

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

struct Direction {
    int y, x;
};

Direction Dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int N, result = 10001, check = 2;
std::vector<std::vector<int>> map;
std::vector<Direction> vec;

void input();
void label_land(int y, int x, int label);
void cal_distance();
void check_island(int y, int x);
int check_min(int y, int x);
bool movable(int y, int x);

int main() {
    input();
    cal_distance();
    std::cout << result << "\n";

    return 0;
}

void input() {
    int num, label = 1;
    std::vector<int> map_x;
    std::cin >> N;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            std::cin >> num;
            if (num > 0)
                map_x.push_back(-1);
            else
                map_x.push_back(0);
        }
        map.push_back(map_x);

        map_x.clear();
        map_x.shrink_to_fit();
    }

    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            if (map[y][x] < 0)
                label_land(y, x, label++);
}

void label_land(int y, int x, int label) {
    std::queue<Direction> que;
    Direction cur{y, x};
    que.push(cur);

    while (!que.empty()) {
        bool edge = false;
        cur = que.front();
        map[y][x] = label;
        que.pop();

        for (int d = 0; d < 4; d++) {
            Direction next{cur.y + Dir[d].y, cur.x + Dir[d].x};
            if (movable(next.y, next.x) && map[next.y][next.x] < 0) {
                que.push(next);
                map[next.y][next.x] = label;
            } else if (movable(next.y, next.x) && map[next.y][next.x] == 0)
                edge = true;
        }
        if (edge)
            vec.push_back(cur);
    }
}

void cal_distance() {
    int count = 0;
    for (int i = 0; i < vec.size() - 1; i++) {
        Direction dir1{vec.at(i)};
        for (int j = i + 1; j < vec.size(); j++) {
            Direction dir2{vec.at(j)};
            if (map[dir1.y][dir1.x] != map[dir2.y][dir2.x]) {
                count = std::abs(dir1.y - dir2.y) + std::abs(dir1.x - dir2.x) - 1;
                result = std::min(result, count);
            }
        }
    }
}

bool movable(int y, int x) {
    if (0 <= y && 0 <= x && y <= N - 1 && x <= N - 1)
        return true;
    return false;
}