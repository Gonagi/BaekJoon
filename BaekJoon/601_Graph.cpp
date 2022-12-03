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

    /*
        if (count == 0) {
            start_y = y;
            start_x = x;
            start_char = map[start_y][start_x];
            visited[start_y][start_x] = true;
        }

        for (int d = 0; d < 4; d++) {
            int next_y = y + dir[d].y;
            int next_x = x + dir[d].x;

            if (can_move(next_y, next_x) && next_y == start_y &&
                next_x == start_x && map[next_y][next_x] == start_char) {
                std::cout << "Yes\n";
                exit(0);
            }
            if (can_move(next_y, next_x) && !visited[next_y][next_x] &&
                map[next_y][next_x] == start_char) {
                visited[next_y][next_x] = true;
                DFS(next_y, next_x, count + 1);
            }
        }
        */
}

bool can_move(int y, int x) {
    if (y < 0 || x < 0 || y > N - 1 || x > M - 1)
        return false;
    return true;
}
