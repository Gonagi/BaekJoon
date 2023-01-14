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
#include <vector>

int N, K, check, max;
bool alphabet[26];
int word[50];
std::vector<int> vec;

void input();
void DFS(int pick, int start, int checked);

int main() {
    input();

    if (K < 5)
        std::cout << 0 << "\n";
    else if (K == 26)
        std::cout << N << "\n";
    else {
        check |= 1 << ('a' - 'a');
        check |= 1 << ('n' - 'a');
        check |= 1 << ('t' - 'a');
        check |= 1 << ('i' - 'a');
        check |= 1 << ('c' - 'a');
        DFS(K - 5, 0, check);
        std::cout << max << "\n";
    }
    return 0;
}

void input() {
    std::string str;

    std::cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int num = 0;
        std::cin >> str;
        for (int idx = 0; idx < str.length(); idx++) {
            num |= 1 << (str[idx] - 'a');
        }
        word[i] = num;
    }
}

void DFS(int pick, int start, int checked) {
    if (pick == 0) {
        int count = 0;
        for (int idx = 0; idx < N; idx++) {
            if ((word[idx] & checked) == word[idx])
                count++;
        }
        if (max < count)
            max = count;
        return;
    }

    for (int idx = start; idx < 26; idx++) {
        if ((checked & (1 << idx)) == 0) {
            checked |= (1 << idx);
            DFS(pick - 1, idx, checked);
            checked &= ~(1 << idx);
        }
    }
}
*/

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