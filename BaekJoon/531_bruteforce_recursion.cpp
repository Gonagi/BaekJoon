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

/*
// 두 동전
// 16197
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Direction {
    int y, x;
};
Direction dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
Direction coin[2];
int N, M, result = 10000;
std::vector<std::vector<char>> board;

void input();
void DFS(Direction coin1, Direction coin2, int count);
bool out(Direction coin);

int main() {
    input();
    DFS(coin[0], coin[1], 0);

    if (result > 10)
        result = -1;

    std::cout << result << "\n";
    return 0;
}

void input() {
    int i = 0;
    std::string str;
    std::vector<char> board_x;

    std::cin >> N >> M;

    for (int y = 0; y < N; y++) {
        std::cin >> str;
        for (int x = 0; x < M; x++) {
            if (str[x] == 'o') {
                coin[i] = {y, x};
                i++;
            }
            board_x.push_back(str[x]);
        }
        board.push_back(board_x);
        board_x.clear();
        board_x.shrink_to_fit();
    }
}

void DFS(Direction coin1, Direction coin2, int count) {
    if (result < count)
        return;

    if (count > 10) {
        result = std::min(result, count);
        return;
    }

    for (int d = 0; d < 4; d++) {
        Direction next_coin1{coin1.y + dir[d].y, coin1.x + dir[d].x};
        Direction next_coin2{coin2.y + dir[d].y, coin2.x + dir[d].x};

        if ((out(next_coin1) && !out(next_coin2)) || (!out(next_coin1) && out(next_coin2))) {
            result = std::min(result, count + 1);
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
    if (coin.y < 0 || coin.y > N - 1 || coin.x < 0 || coin.x > M - 1)
        return true;
    return false;
}
*/

/*
// 에너지 모으기
// 16198

#include <algorithm>
#include <iostream>
#include <vector>

int N, max;
std::vector<int> vec;

void DFS(int sum);

int main() {
    int num;
    std::cin >> N;

    for (int idx = 0; idx < N; idx++) {
        std::cin >> num;
        vec.push_back(num);
    }

    DFS(0);

    std::cout << max << "\n";
    return 0;
}

void DFS(int sum) {
    int start = 1;
    int end = vec.size() - 2;

    if (start > end)
        return;

    for (int idx = start; idx <= end; idx++) {
        int num = vec[idx];
        vec.erase(vec.begin() + idx);
        max = std::max(max, sum + vec[idx - 1] * vec[idx]);
        DFS(sum + vec[idx - 1] * vec[idx]);
        vec.insert(vec.begin() + idx, num);
    }
}
*/

// N-Queen
// 9663

/*
#include <iostream>
#define Max 16

int N, count, arr[Max];

void N_Queen(int row);
bool check(int row);

int main() {
    std::cin >> N;
    N_Queen(0);
    std::cout << count << "\n";
    return 0;
}

void N_Queen(int row) {
    if (row == N) {
        count++;
        return;
    }

    for (int queen = 0; queen < N; queen++) {
        arr[row] = queen;
        if (check(row))
            N_Queen(row + 1);
    }
}

bool check(int row) {
    for (int col = 0; col < row; col++) {
        if (arr[col] == arr[row] || (std::abs(arr[col] - arr[row]) == std::abs(col - row)))
            return false;
    }
    return true;
}
*/

/*
// 스도쿠
// 2580

#include <iostream>
#include <vector>

struct location {
    int y, x;
};
std::vector<location> vec;
std::vector<std::vector<int>> board;

void input();
void DFS(int count);
void print();
bool check(int y, int x, int num);

int main() {
    input();
    DFS(0);
    print();
    return 0;
}

void input() {
    int num;
    std::vector<int> board_x;

    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            std::cin >> num;
            if (num == 0)
                vec.push_back({y, x});
            board_x.push_back(num);
        }
        board.push_back(board_x);

        board_x.clear();
        board_x.shrink_to_fit();
    }
}

void print() {
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            std::cout << board[y][x] << " ";
        }
        std::cout << "\n";
    }
}

void DFS(int count) {
    if (count == vec.size()) {
        print();
        exit(0);
    }

    int cur_y = vec[count].y;
    int cur_x = vec[count].x;
    for (int num = 1; num <= 9; num++) {
        if (check(cur_y, cur_x, num)) {
            board[cur_y][cur_x] = num;
            DFS(count + 1);
        }
    }
    board[cur_y][cur_x] = 0;
}

bool check(int y, int x, int num) {
    for (int idx = 0; idx < 9; idx++) {
        if (board[y][idx] == num )
            return false;
        if (board[idx][x] == num )
            return false;
    }

    for (int cur_y = (y / 3) * 3; cur_y < (y / 3 + 1) * 3; cur_y++) {
        for (int cur_x = (x / 3) * 3; cur_x < (x / 3 + 1) * 3; cur_x++) {
            if (board[cur_y][cur_x] == num )
                return false;
        }
    }

    return true;
}
*/

/*
// 스도미노쿠
// 4574

#include <iostream>
#include <string>
#include <vector>

int N, count = 1, board[9][9];
bool done = false, visited[10][10];

void input();
void DFS(int check);
void print();
bool out(int y, int x);
bool check_all(int y, int x, int num);

int main() {
    while (1) {
        input();
        DFS(0);
        done = false;
        for (int y = 1; y < 10; y++) {
            for (int x = 1; x < 10; x++) {
                visited[y][x] = false;
                board[y - 1][x - 1] = 0;
            }
        }
    }
    return 0;
}

void input() {
    int U, V;
    std::string LU, LV;

    std::cin >> N;

    if (N == 0)
        exit(0);

    for (int idx = 0; idx < N; idx++) {
        std::cin >> U >> LU >> V >> LV;
        board[LU[0] - 'A'][LU[1] - '1'] = U;
        board[LV[0] - 'A'][LV[1] - '1'] = V;

        visited[U][V] = true;
        visited[V][U] = true;
    }
    std::string num;
    for (int i = 1; i <= 9; i++) {
        std::cin >> num;
        board[num[0] - 'A'][num[1] - '1'] = i;
    }
}

void DFS(int check) {
    if (check == 81) {
        print();
        done = true;
        return;
    }

    int y = check / 9;
    int x = check % 9;

    if (board[y][x] != 0)
        DFS(check + 1);
    else {
        for (int num1 = 1; num1 <= 9; num1++) {
            for (int num2 = 1; num2 <= 9; num2++) {
                if (!out(y + 1, x)) {
                    if (num1 != num2 && !visited[num1][num2] &&
                        check_all(y, x, num1) && check_all(y + 1, x, num2)) {
                        board[y][x] = num1;
                        board[y + 1][x] = num2;
                        visited[num1][num2] = true;
                        visited[num2][num1] = true;
                        DFS(check + 1);
                        if (done)
                            return;
                        board[y][x] = 0;
                        board[y + 1][x] = 0;
                        visited[num1][num2] = false;
                        visited[num2][num1] = false;
                    }
                }

                if (!out(y, x + 1)) {
                    if (num1 != num2 && !visited[num1][num2] &&
                        check_all(y, x, num1) && check_all(y, x + 1, num2)) {
                        board[y][x] = num1;
                        board[y][x + 1] = num2;
                        visited[num1][num2] = true;
                        visited[num2][num1] = true;
                        DFS(check + 1);
                        if (done)
                            return;
                        board[y][x] = 0;
                        board[y][x + 1] = 0;
                        visited[num1][num2] = false;
                        visited[num2][num1] = false;
                    }
                }
            }
        }
    }
}

bool out(int y, int x) {
    if (y < 0 || x < 0 || y > 8 || x > 8)
        return true;
    if (board[y][x] != 0)
        return true;
    return false;
}

bool check_all(int y, int x, int num) {
    for (int idx = 0; idx < 9; idx++) {
        if (board[y][idx] == num)
            return false;
        if (board[idx][x] == num)
            return false;
    }

    for (int cur_y = (y / 3) * 3; cur_y < (y / 3 + 1) * 3; cur_y++)
        for (int cur_x = (x / 3) * 3; cur_x < (x / 3 + 1) * 3; cur_x++)
            if (board[cur_y][cur_x] == num)
                return false;
    return true;
}

void print() {
    std::cout << "Puzzle " << count++ << "\n";

    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++)
            std::cout << board[y][x];
        std::cout << "\n";
    }
}
*/

// 알파벳
// 1987

#include <iostream>
#define Max 21

struct Direction {
    int y, x;
};
Direction dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int R, C, max = 1;
char map[Max][Max];
bool visited[26];

void input();
void DFS(int y, int x, int count);
bool movable(int y, int x);

int main() {
    input();
    DFS(0, 0, 1);
    std::cout << max << "\n";
    return 0;
}

void input() {
    std::cin >> R >> C;

    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            std::cin >> map[y][x];
        }
    }
}

void DFS(int y, int x, int count) {
    if (max < count)
        max = count;

    visited[map[y][x] - 'A'] = true;
    for (int d = 0; d < 4; d++) {
        int next_y = y + dir[d].y;
        int next_x = x + dir[d].x;
        if (movable(next_y, next_x) && !visited[map[next_y][next_x] - 'A']) {
             visited[map[next_y][next_x] - 'A'] = true;
            DFS(next_y, next_x, count + 1);
            visited[map[next_y][next_x] - 'A'] = false;
        }
    }
}

bool movable(int y, int x) {
    if (y < 0 || y >= R || x < 0 || x >= C)
        return false;
    return true;
}