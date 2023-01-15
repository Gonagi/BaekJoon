/*
// 부분수열의 합
// 14225

#include <algorithm>
#include <iostream>
#include <vector>

int N;
bool visited[2000001];
std::vector<int> vec;

int main() {
    int num;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> num;
        vec.push_back(num);
    }
    std::sort(vec.begin(), vec.end());

    for (int i = 0; i < (1 << N); i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j))
                sum += vec[j];
        }
        visited[sum] = true;
    }

    for (int num = 1; num <= 2000000; num++) {
        if (!visited[num]) {
            std::cout << num << "\n";
            break;
        }
    }
    return 0;
}
*/

/*
// 가르침
// 1062

#include <iostream>
#include <string>

int N, K, max, word[50];

void input();
void DFS(int count, int cur, int check);

int main() {
    input();

    if (K < 5)
        std::cout << 0 << "\n";
    else if (K == 26)
        std::cout << N << "\n";
    else {
        int check = 0;
        check |= (1 << ('a' - 'a'));
        check |= (1 << ('c' - 'a'));
        check |= (1 << ('i' - 'a'));
        check |= (1 << ('n' - 'a'));
        check |= (1 << ('t' - 'a'));
        DFS(5, 0, check);
        std::cout << max << "\n";
    }
    return 0;
}

void input() {
    std::string str;
    std::cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int check = 0;
        check |= (1 << ('a' - 'a'));
        check |= (1 << ('c' - 'a'));
        check |= (1 << ('i' - 'a'));
        check |= (1 << ('n' - 'a'));
        check |= (1 << ('t' - 'a'));

        std::cin >> str;
        for (int idx = 0; idx < str.length(); idx++)
            if ((check & (1 << (str[idx] - 'a'))) == 0)
                check |= (1 << (str[idx] - 'a'));

        word[i] = check;
    }
}

void DFS(int count, int cur, int check) {
    if (count == K) {
        int count = 0;
        for (int i = 0; i < N; i++) {
            if ((word[i] & check) == word[i])
                count++;
        }
        if (max < count)
            max = count;
        return;
    }

    for (int idx = cur; idx < 26; idx++) {
        if ((check & (1 << idx)) == 0) {
            check |= (1 << idx);
            DFS(count + 1, idx, check);
            check &= ~(1 << idx);
        }
    }
}
*/

// 구슬 탈출 2
// 13460

/*
#include <algorithm>
#include <iostream>
#include <vector>

struct Direction {
    int y, x;
};
Direction dir[4]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
Direction r, b;
unsigned int leftright = (1 << 0) | (1 << 2);
unsigned int updown = (1 << 1) | (1 << 3);
int N, M;
std::vector<std::vector<char>> board;

void input();
int DFS(Direction cur_r, Direction cur_b, int count, unsigned int cur_dir);
Direction move(Direction marble1, Direction marbel2, int d);

int main() {
    input();
    int min = DFS(r, b, 0, 0);
    if (min > 10)
        min = -1;
    std::cout << min << "\n";
    return 0;
}

void input() {
    std::cin >> N >> M;

    for (int y = 0; y < N; y++) {
        std::string str;
        std::vector<char> board_x;

        std::cin >> str;
        for (int x = 0; x < M; x++) {
            board_x.push_back(str[x]);
            if (str[x] == 'R') {
                r.y = y;
                r.x = x;
            }
            if (str[x] == 'B') {
                b.y = y;
                b.x = x;
            }
        }
        board.push_back(board_x);
        board_x.clear();
        board_x.shrink_to_fit();
    }
    board[r.y][r.x] = '.';
    board[b.y][b.x] = '.';
}

int DFS(Direction cur_r, Direction cur_b, int count, unsigned int cur_dir) {
    if (count > 10)
        return count;

    int min_count = 11;

    for (int d = 0; d < 4; d++) {
        if (count != 0 && (cur_dir & (1 << d)) == 0)
            continue;

        Direction next_r = move(cur_r, cur_b, d);
        Direction next_b = move(cur_b, cur_r, d);

        if (next_r.y > 0 && next_b.y > 0) {
            int next_dir = ((1 << d) & leftright) ? updown : leftright;
            min_count = std::min(min_count, DFS(next_r, next_b, count + 1, next_dir));
        } else if (next_r.y < 0 && next_b.y > 0) {
            return count + 1;
        }
    }
    return min_count;
}

Direction move(Direction marble1, Direction marbel2, int d) {
    int back = 1;
    int next_y = marble1.y;
    int next_x = marble1.x;

    while (board[next_y][next_x] == '.') {
        next_y += dir[d].y;
        next_x += dir[d].x;

        if (next_y == marbel2.y && next_x == marbel2.x)
            back = 2;
    }

    if (board[next_y][next_x] == 'O')
        return {-1, -1};
    return {next_y - dir[d].y * back, next_x - dir[d].x * back};
}
*/

#include <iostream>
#include <string>
#include <vector>

struct Direction {
    int y, x;
};
Direction dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
Direction Red, Blue;
int left_right = (1 << 0) | (1 << 2);
int up_down = (1 << 1) | (1 << 3);
int N, M, min = 11;
std::vector<std::vector<char>> board;

void input();
void DFS(Direction cur_R, Direction cur_B, int count, int dir);
Direction move(Direction marble1, Direction marble2, int d);

int main() {
    input();
    DFS(Red, Blue, 0, 0);
    if (min > 10)
        min = -1;
    std::cout << min << "\n";
    return 0;
}

void input() {
    std::string str;
    std::vector<char> board_x;
    std::cin >> N >> M;

    for (int y = 0; y < N; y++) {
        std::cin >> str;
        for (int x = 0; x < M; x++) {
            board_x.push_back(str[x]);
            if (str[x] == 'R') {
                Red.y = y;
                Red.x = x;
            } else if (str[x] == 'B') {
                Blue.y = y;
                Blue.x = x;
            }
        }
        board.push_back(board_x);
        board_x.clear();
        board_x.shrink_to_fit();
    }

    board[Red.y][Red.x] = '.';
    board[Blue.y][Blue.x] = '.';
}

void DFS(Direction cur_R, Direction cur_B, int count, int dir) {
    if (count > 10)
        return ;

    for (int d = 0; d < 4; d++) {
        if (count != 0 && (dir & (1 << d)) == 0)
            continue;

        Direction next_R = move(cur_R, cur_B, d);
        Direction next_B = move(cur_B, cur_R, d);
        
        if (next_R.y > 0 && next_B.y > 0) {
            int next_dir = ((1 << d) & left_right) ? up_down : left_right;
            DFS(next_R, next_B, count + 1, next_dir);
        } else if (next_R.y < 0 && next_B.y > 0) {
            min = std::min(min, count + 1);
            return;
        }
    }
}

Direction move(Direction marble1, Direction marble2, int d) {
    int check = 1;
    Direction next_marble{marble1};

    while (board[next_marble.y][next_marble.x] == '.') {
        next_marble.y += dir[d].y;
        next_marble.x += dir[d].x;

        if (next_marble.y == marble2.y && next_marble.x == marble2.x)
            check = 2;
    }

    if (board[next_marble.y][next_marble.x] == 'O')
        return {-1, -1};
    return {next_marble.y - (dir[d].y * check), next_marble.x - (dir[d].x * check)};
}