/*
// ABCDE
// 13023

#include <iostream>
#include <vector>

int N, M, is_exist = 0;
bool visited[2000];
std::vector<int> vec[2000];

void DFS(int cur, int depth);

int main() {
    int from, to;
    std::cin >> N >> M;

    for (int i = 0; i < M; i++) {
        std::cin >> from >> to;
        vec[from].push_back(to);
        vec[to].push_back(from);
    }

    int i = 0;
    while (i < N && !is_exist) {
        DFS(i, 0);
        i++;
    }

    std::cout << is_exist << "\n";

    return 0;
}

void DFS(int cur, int depth) {
    if (depth == 4) {
        is_exist = 1;
        return;
    }

    for (int index = 0; index < vec[cur].size(); index++) {
        visited[cur] = true;
        int next = vec[cur].at(index);
        if (!visited[next] && !is_exist)
            DFS(next, depth + 1);
        visited[cur] = false;
    }
}
*/

/*
// 시간초과

#include <iostream>

int N, M, is_exist = 0;
int Arr[2001][2001]{0};

void DFS(int cur, int depth);

int main() {
    int from, to;

    std::cin >> N >> M;

    for (int i = 0; i < M; i++) {
        std::cin >> from >> to;
        Arr[from][to] = 1;
        Arr[to][from] = 1;
    }

    int i = 0;
    while (i++ < N && !is_exist)
        DFS(i, 0);

    std::cout << is_exist << "\n";

    return 0;
}

void DFS(int cur, int depth) {
    if (depth == 4) {
        is_exist = 1;
        return;
    }

    for (int index = 0; index < N; index++) {
        if ((Arr[cur][index] != 0) && !is_exist) {
            Arr[cur][index] = 0;
            Arr[index][cur] = 0;
            DFS(index, depth + 1);
            Arr[cur][index] = 1;
            Arr[index][cur] = 1;
        }
    }
}
*/

// DFS와 BFS
// 1260

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int N, M, V;
bool is_exist = false, visited[1000]{false};
int vec[1001][1001]{0};
std::queue<int> que;

void DFS(int cur);
void BFS(int cur, int count);

int main() {
    int from, to;
    std::cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        std::cin >> from >> to;
        vec[from][to] = 1;
        vec[to][from] = 1;
    }

    DFS(V);
    std::cout << "\n";

    for (int i = 1; i <= N; i++)
        visited[i] = false;

    BFS(V, 0);
    std::cout << "\n";

    return 0;
}

void DFS(int cur) {
    visited[cur] = true;
    std::cout << cur << " ";

    for (int next_index = 1; next_index <= N; next_index++) {
        if (vec[cur][next_index] == 1 && !visited[next_index])
            DFS(next_index);
    }
    return;
}

/*
void BFS(int cur, int count) {
    if (count != 0 && que.empty())
        return;

    std::cout << cur << " ";
    visited[cur] = true;

    for (int next_index = 1; next_index <= N; next_index++) {
        if (vec[cur][next_index] == 1 && !visited[next_index]) {
            que.push(next_index);
            visited[next_index] = true;
            count++;
        }
    }

    int next = que.front();
    que.pop();
    if (que.empty())
        std::cout << next << " ";
    BFS(next, count);
}
*/

void BFS(int cur, int count) {
    que.push(cur);
    visited[cur] = true;
    std::cout << cur << " ";

    while (!que.empty()) {
        int next = que.front();
        que.pop();

        for (int next_index = 1; next_index <= N; next_index++) {
            if (vec[next][next_index] == 1 && !visited[next_index]) {
                que.push(next_index);
                visited[next_index] = true;
                std::cout << next_index << " ";
            }
        }
    }
}