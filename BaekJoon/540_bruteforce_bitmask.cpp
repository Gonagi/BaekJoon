/*
// 집합
// 11723

#include <iostream>
#include <string>

void add(int num);
void remove(int num);
int check(int num);
void toggle(int num);
void all();
void empty();

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int M, num, S = 0;
    std::string str;
    std::cin >> M;

    for (int index = 0; index < M; index++) {
        std::cin >> str;

        if (str == "add") {
            std::cin >> num;
            S |= (1 << num);
        }

        else if (str == "remove") {
            std::cin >> num;
            S &= ~(1 << num);
        }

        else if (str == "check") {
            std::cin >> num;
            if (S & (1 << num))
                std::cout << 1 << "\n";
            else
                std::cout << 0 << "\n";
        }

        else if (str == "toggle") {
            std::cin >> num;
            S ^= (1 << num);
        }

        else if (str == "all")
            S = (1 << 21) - 1;

        else if (str == "empty")
            S = 0;
    }

    return 0;
}
*/

/*
// 부분수열의 합
// 1182

#include <iostream>
#include <vector>

void check(std::vector<int> &input);

int N, S, count = 0;

int main() {
    int num;
    std::vector<int> input;

    std::cin >> N >> S;

    for (int i = 0; i < N; i++) {
        std::cin >> num;
        input.push_back(num);
    }

    check(input);

    return 0;
}

void check(std::vector<int> &input) {

    for (int num = 1; num < (1 << N); num++) {
        int sum = 0;
        for (int check = 0; check < N; check++) {
            if (num & (1 << check))
                sum += input.at(check);
        }
        if (sum == S)
            count++;
    }
    std::cout << count << "\n";
}
*/

/*
#include <iostream>
#include <vector>

int N, S, count = 0;
std::vector<int> input;

void DFS(int num);

int main() {
    int num;

    std::cin >> N >> S;

    for (int i = 0; i < N; i++) {
        std::cin >> num;
        input.push_back(num);
    }

    DFS(1);

    std::cout << count << "\n";
    return 0;
}

void DFS(int num) {
    if (num == (1 << N))
        return;

    int sum = 0;

    for (int i = 0; i < N; i++)
        if (num & (1 << i))
            sum += input.at(i);

    if (sum == S)
        count++;

    DFS(num + 1);
}
*/

/*
#include <iostream>
#include <vector>

int N, S, count = 0;
std::vector<int> input;

void check(int cur, int sum);

int main() {
    int num;

    std::cin >> N >> S;

    for (int i = 0; i < N; i++) {
        std::cin >> num;
        input.push_back(num);
    }

    check(0, 0);

    if (S == 0)
        count--;

    std::cout << count << "\n";
    return 0;
}

void check(int cur, int sum) {
    if (cur == N) {
        if (sum == S)
            count++;
        return;
    }

    check(cur + 1, sum);
    check(cur + 1, sum + input.at(cur));
}
*/

// 종이 조각
// 14391

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int N, M, max = 0;
std::vector<std::vector<int>> Square;
std::vector<std::vector<bool>> visited;

void Input();
void DFS(int cur_y, int cur_x);
bool Is_possible(int cur_y, int cur_x);
void cal();

int main() {
    std::cin >> N >> M;
    Input();
    DFS(0, 0);

    std::cout << max << "\n";
}

void Input() {
    std::string num;
    std::vector<int> input;
    std::vector<bool> visit;

    for (int y = 0; y < N; y++) {
        std::cin >> num;
        for (int x = 0; x < M; x++) {
            input.push_back(num.at(x) - '0');
            visit.push_back(false);
        }
        Square.push_back(input);
        visited.push_back(visit);

        input.clear();
        input.shrink_to_fit();
        visit.clear();
        visit.shrink_to_fit();
    }
}

void DFS(int cur_y, int cur_x) {
    if (cur_y == N) {
        DFS(0, cur_x + 1);
        return;
    }

    if (cur_x == M) {
        if(cur_y == N && cur_x == M)
            int a = 3;
        cal();
        return;
    }

    visited[cur_y].at(cur_x) = true;
    DFS(cur_y + 1, cur_x);
    visited[cur_y].at(cur_x) = false;
    DFS(cur_y + 1, cur_x);
}

bool Is_possible(int cur_y, int cur_x) {
    if (cur_y <= -1 || cur_y >= N || cur_x <= -1 || cur_x >= M)
        return false;
    if (visited[cur_y].at(cur_x))
        return false;

    return true;
}

void cal() {
    int sum = 0;
    for (int y = 0; y < N; y++) {
        int temp = 0;
        for (int x = 0; x < M; x++) {
            if (Is_possible(y, x))
                temp = 10 * temp + Square[y].at(x);
            else {
                sum += temp;
                temp = 0;
            }
        }
        sum += temp;
    }

    for (int x = 0; x < M; x++) {
        int temp = 0;
        for (int y = 0; y < N; y++) {
            if (!Is_possible(y, x))
                temp = 10 * temp + Square[y].at(x);
            else {
                sum += temp;
                temp = 0;
            }
        }
        sum += temp;
    }

    max = std::max(max, sum);
}