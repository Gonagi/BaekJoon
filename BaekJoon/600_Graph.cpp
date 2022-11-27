/*
// ABCDE
// 13023

#include <iostream>
#include <vector>

int N, M;
bool is_exist = false;
std::vector<int> linked[2001];
bool visited[2001];

void DFS(int cur, int depth);

int main() {
    int a, b;
    std::cin >> N >> M;

    for (int i = 0; i < M; i++) {
        std::cin >> a >> b;
        linked[a].push_back(b);
        linked[b].push_back(a);
    }

    for (int index = 0; index < N; index++)
        DFS(index, 0);

    if (!is_exist)
        std::cout << 0 << "\n";

    return 0;
}

void DFS(int cur, int depth) {
    if (depth == 4) {
        std::cout << 1 << "\n";
        is_exist = true;
        return;
    }

    for (int index = 0; index < linked[cur].size(); index++) {
        int next = linked[cur].at(index);
        if (!visited[next] && !is_exist) {
            visited[cur] = true;
            DFS(next, depth + 1);
            visited[cur] = false;
        }
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

/*
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
*/

/*
#include <iostream>
#include <queue>
#include <vector>

int N, M, V;
int linked[1001][1001];
bool visited[1001];
std::queue<int> que;

void DFS(int cur, int count);
void BFS(int cur, int count);

int main() {
    int a, b;
    std::cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        std::cin >> a >> b;
        linked[a][b]++;
        linked[b][a]++;
    }

    DFS(V, 0);

    std::cout << "\n";
    for (int i = 1; i <= N; i++)
        visited[i] = false;

    BFS(V, 0);

    return 0;
}

void DFS(int cur, int count) {
    visited[cur] = true;
    std::cout << cur << " ";

    for (int index = 1; index <= N; index++)
        if (!visited[index] && linked[cur][index] > 0)
            DFS(index, count + 1);
}

void BFS(int cur, int count) {
    que.push(cur);
    std::cout << cur << " ";
    visited[cur] = true;

    while (!que.empty()) {
        int from = que.front();
        que.pop();

        for (int to = 1; to <= N; to++) {
            if (!visited[to] && linked[from][to] > 0 && linked[to][from] > 0) {
                linked[from][to]--;
                linked[to][from]--;

                std::cout << to << " ";
                que.push(to);
                visited[to] = true;
            }
        }
    }
}
*/

// 연결 요소의 개수
// 11724

#include <iostream>
#include <vector>

int N, M, count = 0;
bool linked[1001][1001];
bool visited[1001];

void input();
void count_link();
void DFS(int num);

int main() {
    input();
    count_link();
    std::cout << count << "\n";

    return 0;
}

void input() {
    int u, v;
    std::cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        std::cin >> u >> v;
        linked[u][v] = true;
        linked[v][u] = true;
    }
}

void count_link() {
    for (int num = 1; num <= N; num++) {
        if (!visited[num]) {
            visited[num] = true;
            DFS(num);
            count++;
        }
    }
}

void DFS(int num) {
    for (int to = 1; to <= N; to++) {
        if (!visited[to] && linked[num][to]) {
            visited[to] = true;
            DFS(to);
        }
    }
}