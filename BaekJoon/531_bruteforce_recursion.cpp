/*
// 로또
// 6603
#include <iostream>
#include <vector>

#define Max 50

int k, arr[14];
bool visited[14];
std::vector<int> S;

void DFS(int cur, int count);

int main() {
    while (1) {
        std::cin >> k;
        if (k == 0)
            break;

        int num;
        for (int idx = 0; idx < k; idx++) {
            std::cin >> num;
            S.push_back(num);
        }
        DFS(0, 0);
        std::cout << "\n";

        for (int idx = 0; idx < k; idx++)
            visited[idx] = false;
        S.clear();
        S.shrink_to_fit();
    }
    return 0;
}

void DFS(int cur, int count) {
    if (count == 6) {
        for (int idx = 0; idx < 6; idx++)
            std::cout << arr[idx] << " ";
        std::cout << "\n";
        return;
    }

    for (int idx = cur; idx < k; idx++) {
        if (!visited[idx]) {
            visited[idx] = true;
            arr[count] = S[idx];
            DFS(idx, count + 1);
            visited[idx] = false;
        }
    }
}
*/

/*
// 부분수열의 합
// 1182

#include <iostream>
#include <vector>

int N, S, count;
bool visited[20];
std::vector<int> vec;

void DFS(int sum, int cur);

int main() {
    int num;
    std::cin >> N >> S;

    for (int idx = 0; idx < N; idx++) {
        std::cin >> num;
        vec.push_back(num);
    }

    DFS(0, 0);
    if (S == 0)
        count--;
    std::cout << count << "\n";
    return 0;
}

void DFS(int sum, int cur) {
    if (cur == N) {
        if (sum == S)
            count++;
        return;
    }

    DFS(sum, cur + 1);
    DFS(sum + vec[cur], cur + 1);
}
*/

/*
// 부분수열의 합
// 14225

#include <iostream>
#include <vector>
#define Max 2000000

int N;
bool visited[Max];
std::vector<int> S;

void DFS(int sum, int cur);

int main() {
    int num;

    std::cin >> N;
    for (int idx = 0; idx < N; idx++) {
        std::cin >> num;
        S.push_back(num);
    }

    DFS(0, 0);

    for (int num = 1; num <= Max; num++) {
        if (!visited[num]) {
            std::cout << num << "\n";
            break;
        }
    }
    return 0;
}

void DFS(int sum, int cur) {
    if (cur == N) {
        visited[sum] = true;
        return;
    }

    DFS(sum, cur + 1);
    DFS(sum + S[cur], cur + 1);
}
*/

/*
// 연산자 끼워넣기
// 14888

#include <algorithm>
#include <iostream>
#include <vector>
#define Max 1000000000

int N, max = -Max, min = Max, oper[4];
std::vector<int> A;

void input();
void DFS(int count, int cal);

int main() {
    input();
    DFS(0, A[0]);
    std::cout << max << "\n";
    std::cout << min << "\n";
    return 0;
}

void input() {
    int num;

    std::cin >> N;

    for (int idx = 0; idx < N; idx++) {
        std::cin >> num;
        A.push_back(num);
    }

    for (int idx = 0; idx < 4; idx++) {
        std::cin >> num;
        oper[idx] = num;
    }
}

void DFS(int count, int cal) {
    if (count == N - 1) {
        min = std::min(min, cal);
        max = std::max(max, cal);
        return;
    }

    for (int idx = 0; idx < 4; idx++) {
        if (oper[idx] != 0) {
            oper[idx]--;
            if (idx == 0)
                DFS(count + 1, cal + A[count + 1]);
            if (idx == 1)
                DFS(count + 1, cal - A[count + 1]);
            if (idx == 2)
                DFS(count + 1, cal * A[count + 1]);
            if (idx == 3) {
                if (cal > 0)
                    DFS(count + 1, cal / A[count + 1]);
                else
                    DFS(count + 1, -1 * ((-1 * cal) / A[count + 1]));
            }
            oper[idx]++;
        }
    }
}
*/

/*
// 연산자 끼워넣기 (2)
// 15658

#include <algorithm>
#include <iostream>
#include <vector>
#define Max 1000000000

int N, max = -Max, min = Max, oper[4];
std::vector<int> A;

void input();
void DFS(int count, int cal);

int main() {
    input();
    DFS(0, A[0]);
    std::cout << max << "\n";
    std::cout << min << "\n";
    return 0;
}

void input() {
    int num;

    std::cin >> N;

    for (int idx = 0; idx < N; idx++) {
        std::cin >> num;
        A.push_back(num);
    }

    for (int idx = 0; idx < 4; idx++) {
        std::cin >> num;
        oper[idx] = num;
    }
}

void DFS(int count, int cal) {
    if (count == N - 1) {
        min = std::min(min, cal);
        max = std::max(max, cal);
        return;
    }

    for (int idx = 0; idx < 4; idx++) {
        if (oper[idx] != 0) {
            oper[idx]--;
            if (idx == 0)
                DFS(count + 1, cal + A[count + 1]);
            if (idx == 1)
                DFS(count + 1, cal - A[count + 1]);
            if (idx == 2)
                DFS(count + 1, cal * A[count + 1]);
            if (idx == 3) {
                if (cal > 0)
                    DFS(count + 1, cal / A[count + 1]);
                else
                    DFS(count + 1, -1 * ((-1 * cal) / A[count + 1]));
            }
            oper[idx]++;
        }
    }
}
*/

/*
// 테트로미노
// 14500

#include <algorithm>
#include <iostream>
#define Max 500

void input();
void DFS(int count, int sum, int y, int x);
void H_shape(int y, int x);
bool can_move(int y, int x);

struct Direction {
    int y, x;
};
Direction dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int N, M, arr[Max][Max], max;
bool visited[Max][Max];

int main() {
    input();
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            DFS(0, 0, y, x);
            H_shape(y, x);
        }
    }

    std::cout << max << "\n";
    return 0;
}

void input() {
    std::cin >> N >> M;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            std::cin >> arr[y][x];
        }
    }
}

void DFS(int count, int sum, int y, int x) {
    if (count == 4) {
        max = std::max(max, sum);
        return;
    }

    for (int d = 0; d < 4; d++) {
        int next_y = y + dir[d].y;
        int next_x = x + dir[d].x;

        if (can_move(next_y, next_x) && !visited[next_y][next_x]) {
            visited[next_y][next_x] = true;
            DFS(count + 1, sum + arr[next_y][next_x], next_y, next_x);
            visited[next_y][next_x] = false;
        }
    }
}

void H_shape(int y, int x) {
    if (0 <= y && y <= N - 2 && 0 <= x && x <= M - 3) {
        max = std::max(max, arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y + 1][x + 1]);
        max = std::max(max, arr[y][x + 1] + arr[y + 1][x] + arr[y + 1][x + 1] + arr[y + 1][x + 2]);
    }
    if (0 <= y && y <= N - 3 && 0 <= x && x <= M - 2) {
        max = std::max(max, arr[y][x + 1] + arr[y + 1][x] + arr[y + 1][x + 1] + arr[y + 2][x + 1]);
        max = std::max(max, arr[y][x] + arr[y + 1][x] + arr[y + 1][x + 1] + arr[y + 2][x]);
    }
}

bool can_move(int y, int x) {
    if (y < 0 || N - 1 < y || x < 0 || M - 1 < x)
        return false;
    return true;
}
*/

// 두 동전
// 16197

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define Max 20

struct Direction {
    int y, x;
};
Direction coin[2], dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int N, M, min = 100;
std::vector<std::vector<char>> board;

void input();
void DFS(Direction coin1, Direction coin2, int count);
bool out(Direction coin);

int main() {
    input();
    DFS(coin[0], coin[1], 0);
    if (min > 10)
        min = -1;
    std::cout << min << "\n";
    return 0;
}

void input() {
    std::string str;
    int i = 0;
    std::vector<char> board_x;

    std::cin >> N >> M;

    for (int y = 0; y < N; y++) {
        std::cin >> str;
        for (int x = 0; x < M; x++) {
            board_x.push_back(str[x]);
            if (str[x] == 'o') {
                coin[i] = {y, x};
                i++;
            }
        }
        board.push_back(board_x);
        board_x.clear();
        board_x.shrink_to_fit();
    }
}

void DFS(Direction coin1, Direction coin2, int count) {
    if (min < count)
        return;
    if (count > 10)
        return;
        
    for (int d = 0; d < 4; d++) {
        Direction next_coin1{coin1.y + dir[d].y, coin1.x + dir[d].x};
        Direction next_coin2{coin2.y + dir[d].y, coin2.x + dir[d].x};

        if ((out(next_coin1) && !out(next_coin2)) || (!out(next_coin1) && out(next_coin2))) {
            min = std::min(min, count + 1);
            return;
        }

        if (!out(next_coin1) && !out(next_coin2)) {
            if (board[next_coin1.y][next_coin1.x] == '#' && board[next_coin2.y][next_coin2.x] == '#')
                continue;
            if (board[next_coin1.y][next_coin1.x] == '#')
                next_coin1 = coin1;
            if (board[next_coin2.y][next_coin2.x] == '#')
                next_coin2 = coin2;
            DFS(next_coin1, next_coin2, count + 1);
        }
    }
}

bool out(Direction coin) {
    if (coin.y < 0 || N - 1 < coin.y || coin.x < 0 || M - 1 < coin.x)
        return true;
    return false;
}
