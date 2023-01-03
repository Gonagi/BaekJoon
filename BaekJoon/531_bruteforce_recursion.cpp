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