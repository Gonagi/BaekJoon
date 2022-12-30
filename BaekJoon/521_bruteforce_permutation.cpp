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