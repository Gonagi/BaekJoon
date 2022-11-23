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
        int next = vec[cur].at(index);
        visited[cur] = true;
        if (!visited[next] && !is_exist) 
            DFS(next, depth + 1);
        visited[cur] = false;
    }
}