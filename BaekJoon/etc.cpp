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