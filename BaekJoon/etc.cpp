// 듣보잡
// 1764

/*
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    int N, M;
    std::string str;
    std::vector<std::string> vec;
    std::map<std::string, int> m;

    std::cin >> N >> M;

    for (int i = 0; i < N + M; i++) {
        std::cin >> str;
        m[str]++;
        if (m[str] > 1)
            vec.push_back(str);
    }

    std::sort(vec.begin(), vec.end());

    std::cout << vec.size() << "\n";

    for (auto o : vec)
        std::cout << o << "\n";

    return 0;
}
*/

/*
// ATM
// 11399

#include <algorithm>
#include <iostream>
#include <vector>

int N;
std::vector<int> vec, result;

int main() {
    int num, sum = 0;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> num;
        vec.push_back(num);
    }

    std::sort(vec.begin(), vec.end());

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            sum += vec[j];
        }
        result.push_back(sum + vec.at(i));
        sum = 0;
    }

    for (int i = 0; i < N; i++)
        sum += result.at(i);

    std::cout << sum << "\n";

    return 0;
}
*/

/*1
// 비밀번호 찾기
// 17219

#include <iostream>
#include <map>
#include <string>

int N, M;
std::map<std::string, std::string> memo;

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::string site, ID;
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        std::cin >> site >> ID;
        memo.insert({site, ID});
    }

    for (int i = 0; i < M; i++) {
        std::cin >> site;
        std::cout << memo[site] << "\n";
    }
    return 0;
}
*/

/*
// 동전 0
// 11047

#include <iostream>
#include <vector>
int N, K;
std::vector<int> coin;

int main() {
    int input, count = 0;
    std::cin >> N >> K;

    for (int i = 0; i < N; i++) {
        std::cin >> input;
        coin.push_back(input);
    }

    for (int i = N - 1; i >= 0; i--) {
        count += K / coin[i];
        K %= coin[i];
    }

    std::cout << count << "\n";

    return 0;
}
*/

/*
// 계단 오르기
// 2579

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> stairs, dp;

int main() {
    int top, input;

    std::cin >> top;

    for (int i = 0; i < top; i++) {
        std::cin >> input;
        stairs.push_back(input);
    }

    dp.push_back(stairs[0]);
    if (2 <= top)
        dp.push_back(stairs[0] + stairs[1]);
    if (3 <= top)
        dp.push_back(std::max(stairs[0], stairs[1]) + stairs[2]);

    for (int cur = 3; cur < top; cur++) {
        dp.push_back(std::max(dp[cur - 2] + stairs[cur],
                              dp[cur - 3] + stairs[cur - 1] + stairs[cur]));
    }

    std::cout << dp[top - 1] << "\n";

    return 0;
}
*/

/*
// 별찍기 -11
// 2448

#include <cstring>
#include <iostream>
using namespace std;

char star[3072][6144];//세로 N, 가로 2N-1

void print(int x, int y, int n) {
        if (n == 3) {
                star[x][y] = '*';
                star[x + 1][y - 1] = '*';
                star[x + 2][y - 2] = '*';
                star[x + 2][y - 1] = '*';
                star[x + 2][y] = '*';
                star[x + 2][y + 1] = '*';
                star[x + 2][y + 2] = '*';
                star[x + 1][y + 1] = '*';
        }
        else {
                print(x, y, n / 2);
                print(x + n / 2, y - n / 2, n / 2);
                print(x + n / 2, y + n / 2, n / 2);
        }
}

int main() {
        int N;
        cin >> N;
        memset(star, ' ', sizeof(star));

        print(0, N - 1, N);

        for (int i = 0; i < N; i++) {
                for (int j = 0; j < 2 * N - 1; j++) {
                        cout << star[i][j];
                }
                cout << '\n';
        }
        return 0;
}
*/

/*
// N-Queen
// 9663

#include <iostream>
#define Max 15

int N, count, arr[Max];

void N_Queen(int row);
bool check(int col);

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
        if (arr[row] == arr[col] || std::abs(row - col) == std::abs(arr[col] - arr[row]))
            return false;
    }
    return true;
}
*/

/*
// 트리의 순회
// 2263

#include <iostream>
#define Max 100000 + 1

int n, inorder[Max], postorder[Max], preorder[Max], arr[Max];

void pre(int in_b, int in_e, int post_b, int post_e);

int main() {
    std::cin >> n;

    for (int idx = 0; idx < n; idx++)
        std::cin >> inorder[idx];

    for (int idx = 0; idx < n; idx++)
        std::cin >> postorder[idx];

    for (int idx = 0; idx < n; idx++)
        arr[inorder[idx]] = idx;

    pre(0, n - 1, 0, n - 1);
    return 0;
}

void pre(int in_b, int in_e, int post_b, int post_e) {
    if (in_b > in_e || post_b > post_e)
        return;

    int root = postorder[post_e];
    int root_index = arr[root];
    int left_count = root_index - in_b;

    std::cout << root << ' ';

    pre(in_b, root_index - 1, post_b, post_b + left_count - 1);
    pre(root_index + 1, in_e, post_b + left_count, post_e - 1);
}
*/

// 가운데를 말해요
// 1655

#include <functional>
#include <iostream>
#include <queue>

int N, num;
std::priority_queue<int, std::vector<int>, std::greater<int>> right_que;
std::priority_queue<int> left_que;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N;

    for (int idx = 0; idx < N; idx++) {
        std::cin >> num;

        if (left_que.size() == right_que.size())
            left_que.push(num);
        else
            right_que.push(num);

        if (!left_que.empty() && !right_que.empty()) {
            if (left_que.top() > right_que.top()) {
                int tmp1 = left_que.top();
                int tmp2 = right_que.top();
                left_que.pop();
                right_que.pop();
                left_que.push(tmp2);
                right_que.push(tmp1);
            }
        }
        std::cout << left_que.top() << '\n';
    }
    return 0;
}