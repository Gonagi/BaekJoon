/*
// Two Dots
// 16929

#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Direction {
    int y, x;
};

Direction dir[4]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
std::vector<std::vector<char>> map;
std::vector<std::vector<bool>> visited;
int N, M, start_y, start_x;
char start_char;

void input();
void DFS(int y, int x, int count);
bool can_move(int y, int x);

int main() {
    input();
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (!visited[y][x]) {
                DFS(y, x, 0);
            }
        }
    }

    std::cout << "No\n";
    return 0;
}

void input() {
    std::string str;
    std::vector<char> input_x;
    std::vector<bool> check_x;
    std::cin >> N >> M;

    for (int y = 0; y < N; y++) {
        std::cin >> str;
        for (int x = 0; x < M; x++) {
            input_x.push_back(str.at(x));
        }
        map.push_back(input_x);

        check_x.assign(N, false);
        visited.assign(N, check_x);

        input_x.clear();
        input_x.shrink_to_fit();
    }
}

void DFS(int y, int x, int count) {
    visited[y][x] = true;
    if (count == 0) {
        start_y = y;
        start_x = x;
        start_char = map[y][x];
    }

    for (int d = 0; d < 4; d++) {
        int next_y = y + dir[d].y;
        int next_x = x + dir[d].x;

        if (next_y == start_y && next_x == start_x && count >= 3) {
            std::cout << "Yes\n";
            exit(0);
        }

        else if (can_move(next_y, next_x) && !visited[next_y][next_x] &&
                 map[next_y][next_x] == start_char) {
            count++;
            DFS(next_y, next_x, count);
            visited[next_y][next_x] = false;
            count--;
        }
    }
}

bool can_move(int y, int x) {
    if (y < 0 || x < 0 || y > N - 1 || x > M - 1)
        return false;
    return true;
}
*/

// 서울 지하철 2호선
// 16947

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int N, first_num, result = 100000000, counts = 0;
bool is_exist = false, c = false;
std::vector<int> linked[3001];
std::vector<bool> visited(3001, false), check(3001, false);

void input();
void DFS(int num, int count);
void print(int num);
void distance(int num);

int main() {
    input();
    for (int num = 1; num <= N; num++) {
        first_num = num;
        DFS(num, 0);
        if (is_exist) {
            check[num] = true;
            break;
        }
        visited.assign(N + 1, false);
    }

    for (int num = 1; num <= N; num++) {
        print(num);
    }

    return 0;
}

void input() {
    int dot1, dot2;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> dot1 >> dot2;
        linked[dot1].push_back(dot2);
        linked[dot2].push_back(dot1);
    }
}

void DFS(int num, int count) {
    for (int next_index = 0; next_index < linked[num].size(); next_index++) {
        int next_num = linked[num][next_index];

        if (next_num == first_num && count > 1 && !check[next_num]) {
            check[num] = true;
            is_exist = true;
            return;
        }

        if (!visited[next_num]) {
            visited[num] = true;
            DFS(next_num, count + 1);
            if (is_exist) {
                check[next_num] = true;
                return;
            }
        }
    }
}

void print(int num) {
    if (check[num])
        std::cout << 0 << " ";
    else {
        visited.assign(N + 1, false);
        result = 10000000;
        counts = 0;
        distance(num);
    }
}

void distance(int num) {
    visited[num] = true;

    if (check[num]) {
        result = std::min(result, counts);
        std::cout << result << " ";
        return;
    }

    for (int next_index = 0; next_index < linked[num].size(); next_index++) {
        int next_num = linked[num][next_index];

        if (!visited[next_num]) {
            counts++;
            distance(next_num);
            counts--;
        }
    }
}