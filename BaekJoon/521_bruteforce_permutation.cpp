/*
// 부등호
// 2529

// 순열
#include <algorithm>
#include <iostream>
#include <vector>

#define Max 10

int k;
std::vector<char> inequality;
std::vector<int> min, max;

bool check(const std::vector<int> &vec);

int main() {
    char ch;
    std::cin >> k;

    for (int i = 0; i < k; i++) {
        std::cin >> ch;
        inequality.push_back(ch);
    }
    for (int num = 0; num <= 9; num++)
        min.push_back(num);
    for (int num = 9; num >= 0; num--)
        max.push_back(num);

    do {
        if (check(max))
            break;

    } while (std::prev_permutation(max.begin(), max.end()));

    do {
        if (check(min))
            break;
    } while (std::next_permutation(min.begin(), min.end()));

    for (int idx = 0; idx <= k; idx++)
        std::cout << max[idx];
    std::cout << "\n";

    for (int idx = 0; idx <= k; idx++)
        std::cout << min[idx];
    std::cout << "\n";

    return 0;
}

bool check(const std::vector<int> &vec) {
    for (int idx = 0; idx < k; idx++) {
        if (inequality[idx] == '<' && vec[idx] > vec[idx + 1])
            return false;
        else if (inequality[idx] == '>' && vec[idx] < vec[idx + 1])
            return false;
    }
    return true;
}
*/

/*
// 백트래킹

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define Max 10

bool visited[Max];
std::vector<char> inequality;
std::vector<std::string> ans;

int k;

void func(int count, std::string str);
void check(std::string str);

int main() {
    char ch;
    std::cin >> k;

    for (int i = 0; i < k; i++) {
        std::cin >> ch;
        inequality.push_back(ch);
    }

    func(0, "");

    std::sort(ans.begin(), ans.end());

    std::cout << ans[ans.size() - 1] << "\n";
    std::cout << ans[0] << "\n";
    return 0;
}

void func(int count, std::string str) {
    if (count == k + 1) {
        check(str);
        return;
    }

    for (int num = 0; num <= 9; num++) {
        if (!visited[num]) {
            visited[num] = true;
            func(count + 1, str + std::to_string(num));
            visited[num] = false;
        }
    }
}

void check(std::string str) {
    for (int idx = 0; idx < k; idx++) {
        if (inequality[idx] == '<' && str[idx] > str[idx + 1])
            return;
        if (inequality[idx] == '>' && str[idx] < str[idx + 1])
            return;
    }

    ans.push_back(str);
}
*/

/*
// 단어 수학
// 1339

// 시간 456ms
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int N, alphabet[26], count, max;
bool visited[26];
std::vector<std::string> vec;
std::vector<int> num_vec;

void input();
void solve();

int main() {
    input();
    solve();
    std::cout << max << "\n";
    return 0;
}

void input() {
    std::string str;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> str;
        for (int idx = 0; idx < str.size(); idx++) {
            if (!visited[str.at(idx) - 'A']) {
                visited[str.at(idx) - 'A'] = true;
                count++;
            }
        }
        vec.push_back(str);
    }

    for (int num = 9; num >= 10 - count; num--)
        num_vec.push_back(num);
}

void solve() {
    do {
        int sum = 0, index = 0;
        for (int idx = 0; idx < 26; idx++) {
            if (visited[idx]) {
                alphabet[idx] = num_vec[index];
                index++;
                if(index == count)
                    break;
            }
        }

        for (int i = 0; i < vec.size(); i++) {
            int cur_num = 0, digit = 1;
            for (int idx = vec[i].size() - 1; idx >= 0; idx--) {
                cur_num += (digit * alphabet[vec[i][idx] - 'A']);
                digit *= 10;
            }
            sum += cur_num;
        }
        max = std::max(max, sum);

    } while (std::prev_permutation(num_vec.begin(), num_vec.end()));
}
*/

// 시간 0ms
/*
#include <algorithm>
#include <iostream>
#include <string>

bool comp(int a, int b) {
    return a > b;
}
void input();
void solve();

int N, alphabet[26], sum;

int main() {
    input();
    solve();
    std::cout << sum << "\n";
    return 0;
}

void input() {
    std::string str;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int digit = 1;
        std::cin >> str;
        for (int idx = str.size() - 1; idx >= 0; idx--) {
            alphabet[str[idx] - 'A'] += digit;
            digit *= 10;
        }
    }
    std::sort(alphabet, alphabet + 26, comp);
}

void solve() {
    int num = 9;

    for (int idx = 0; idx < 26; idx++) {
        if (alphabet[idx] == 0)
            break;
        sum += (num * alphabet[idx]);
        num--;
    }
}
*/

// 연산자 끼워넣기
// 14888

#include <algorithm>
#include <iostream>
#include <vector>
#define Max 1000000000
#define Min -1000000000

char Ch[4] = {'+', '-', '*', '/'};
int N, oper[4];
long max = Min, min = Max;
std::vector<long> A;
std::vector<char> oper_vec;

void input();
void solve();
long cal();

int main() {
    input();
    solve();
    std::cout << max << "\n";
    std::cout << min << "\n";
    return 0;
}

void input() {
    long num;

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> num;
        A.push_back(num);
    }

    for (int i = 0; i < 4; i++) {
        char ch = Ch[i];
        std::cin >> oper[i];
        for (int idx = 0; idx < oper[i]; idx++)
            oper_vec.push_back(ch);
    }
    std::sort(oper_vec.begin(), oper_vec.end());
}

void solve() {
    do {
        max = std::max(max, cal());
        min = std::min(min, cal());
    } while (std::next_permutation(oper_vec.begin(), oper_vec.end()));
}

long cal() {
    long sum = A[0];

    for (int idx = 0; idx < N; idx++) {
        switch (oper_vec[idx]) {
        case '+':
            sum += A[idx + 1];
            break;
        case '-':
            sum -= A[idx + 1];
            break;
        case '*':
            sum *= A[idx + 1];
            break;
        case '/':
            if (sum > 0) {
                sum /= A[idx + 1];
            } else {
                sum = -1 * ((-1 * sum) / A[idx + 1]);
            }
            break;
        }
    }
    return sum;
}